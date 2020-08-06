#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 20
#define TRAIN_FILE "trains.dat"
#define TICKET_FILE "tickets.dat"
#define TEMP_FILE_1 "temp1.dat"
#define TEMP_FILE_2 "temp2.dat"

#define MAX_SEATS 20
#define TICKET_PRICE 100

int nextPNR=1;

struct Train
{
  int trainNo;
  char source[MAX_STR_SIZE];
  char destination[MAX_STR_SIZE];
  int seatsLeft;
};

struct Ticket
{
  int pnr;
  char name[MAX_STR_SIZE];
  int trainNo;
  int price;
};

typedef struct Train Train;
typedef struct Ticket Ticket;

int showTrainData(Train train)
{
  printf("\nTrain Data: \n");
  printf("  Train Number: %d\n",train.trainNo);
  // printf("TRAIN SOURCE: %s\n",train.source);
  // printf("TRAIN DESTINATION: %s\n",train.destination);
  printf("  Seats Left: %d\n",train.seatsLeft);
  return 0;
}

int showTicketData(Ticket ticket)
{
  printf("\nTicket Data: \n");
  printf("  PNR: %d\n", ticket.pnr);
  printf("  Name: %s\n", ticket.name);
  printf("  Train No: %d\n", ticket.trainNo);
  printf("  Price: %d Rs.\n",ticket.price);
}

int addTrain(int trainNo, char source[], char destination[])
{
  Train train;
  train.trainNo = trainNo;
  strcpy(train.source,source);
  strcpy(train.destination, destination);
  train.seatsLeft = MAX_SEATS;
  FILE *outfile;
  outfile = fopen(TRAIN_FILE,"a");
  if(outfile==NULL)
  {
    printf("error loading train file !\n");
    return 1;
  }

  fwrite(&train,sizeof(Train),1,outfile);
  fclose(outfile);
  return 0;
}

int enquiry(char source[], char destination[])
{
  Train train={};
  Train myTrain={};
  FILE *infile;
  if(strcmp(source,"Delhi"))
  {
    printf("No Such Train Found!\n");
    return 0;
  }

  infile = fopen(TRAIN_FILE,"r");


  if(infile==NULL)
  {
    printf("error reading the train file !\n");
    return 1;
  }

  while(fread(&train,sizeof(Train),1,infile))
  {
    if(!strcmp(train.source,source)  && !strcmp(train.destination,destination))
    {
      myTrain = train;
    }
  }
  if(!myTrain.trainNo)
  {
    printf("No Such Train Found!\n");
    fclose(infile);
    return 0;
  }

  showTrainData(myTrain);
  fclose(infile);
  return 0;
}

int buyTicket(char name[], char source[], char destination[])
{
  Train train={};
  Train myTrain={};
  Ticket myTicket;

  if(strcmp(source,"Delhi"))
  {
    printf("No Such Train Found!\n");
    return 0;
  }

  if(rename(TRAIN_FILE,TEMP_FILE_1))
  {
    printf("Error: Cannot rename file\n");
    return 1;
  }

  FILE *intrainfile = fopen(TEMP_FILE_1,"r");
  if(intrainfile ==NULL)
  {
    printf("error opening the temp file!\n");
    rename(TEMP_FILE_1,TRAIN_FILE);
    return 1;
  }

  FILE *outtrainfile = fopen(TRAIN_FILE,"w");
  if(outtrainfile ==NULL)
  {
    printf("error opening the train file!\n");
    rename(TEMP_FILE_1,TRAIN_FILE);
    return 1;
  }

  FILE *ticketfile = fopen(TICKET_FILE,"a");
  if(ticketfile==NULL)
  {
    printf("error opening the ticket file\n");
    return 1;
  }

  while(fread(&train,sizeof(Train),1,intrainfile))
  {
    if(!strcmp(train.source,source)  && !strcmp(train.destination,destination))
    {
       myTrain = train;
    }
    else fwrite(&train,sizeof(Train),1,outtrainfile);
  }
  fclose(intrainfile);

  if(!myTrain.trainNo)
  {
    printf("No Such Train found!\n");
    remove(TEMP_FILE_1);
    fclose(outtrainfile);
    fclose(ticketfile);
    return 0;
  }

  if(!myTrain.seatsLeft)
  {
    printf("Sorry, no seats left on that train!\n");
    fclose(outtrainfile);
    fclose(ticketfile);
    remove(TEMP_FILE_1);
    return 0;
  }


  strcpy(myTicket.name,name);
  myTicket.trainNo = myTrain.trainNo;
  myTicket.pnr = nextPNR;
  myTicket.price = TICKET_PRICE;

  myTrain.seatsLeft--;
  nextPNR++;

  showTicketData(myTicket);
  fwrite(&myTrain,sizeof(Train),1,outtrainfile);
  fwrite(&myTicket,sizeof(Ticket),1,ticketfile);

  fclose(outtrainfile);
  fclose(ticketfile);
  remove(TEMP_FILE_1);
  return 0;
}

int cancelTicket(int pnr)
{
  Train train={};
  Ticket ticket={};
  Ticket myTicket={};

  if(rename(TICKET_FILE,TEMP_FILE_2))
  {
    printf("Error: Cannot rename file\n");
    return 1;
  }

  FILE *inTicketFile = fopen(TEMP_FILE_2,"r");
  if(inTicketFile==NULL)
  {
    printf("error opening the temp file\n");
    rename(TEMP_FILE_2,TICKET_FILE);
    return 1;
  }

  FILE *outTicketFile = fopen(TICKET_FILE,"w");
  if(inTicketFile==NULL)
  {
    printf("error opening the ticket file\n");
    rename(TEMP_FILE_2,TICKET_FILE);
    return 1;
  }

  while(fread(&ticket,sizeof(Ticket),1,inTicketFile))
  {
    if(ticket.pnr==pnr) {myTicket = ticket;}
    else fwrite(&ticket,sizeof(Ticket),1,outTicketFile);
  }

  fclose(inTicketFile);
  fclose(outTicketFile);
  remove(TEMP_FILE_2);

  if(!myTicket.pnr)
  {
    printf("No Such Ticket Exists!\n");
    return 0;
  }

  if(rename(TRAIN_FILE,TEMP_FILE_1))
  {
    printf("Error: Cannot rename file\n");
    return 1;
  }

  FILE *inTrainFile = fopen(TEMP_FILE_1,"r");
  if(inTrainFile ==NULL)
  {
    printf("error opening the temp file!\n");
    rename(TEMP_FILE_1,TRAIN_FILE);
    return 1;
  }

  FILE *outTrainFile = fopen(TRAIN_FILE,"w");
  if(outTrainFile ==NULL)
  {
    printf("error opening the train file!\n");
    rename(TEMP_FILE_1,TRAIN_FILE);
    return 1;
  }

  while(fread(&train,sizeof(Train),1,inTrainFile))
  {
    if(train.trainNo==myTicket.trainNo) train.seatsLeft++;
    fwrite(&train,sizeof(Train),1,outTrainFile);
  }

  int refund = myTicket.price / 2;
  printf("You have been refunded %d Rs. for cancelling the following ticket:\n",refund);
  showTicketData(myTicket);

  fclose(inTrainFile);
  fclose(outTrainFile);
  remove(TEMP_FILE_1);
  return 0;
}

int showMenu()
{
  printf("------------------------------------------\n");
  printf("Welcome to the Railway Reservation System!\n");
  printf("------------------------------------------\n\n\n");
  printf("[1] Enquiry\n");
  printf("[2] Buy Ticket\n");
  printf("[3] Cancel Ticket\n\n");

  printf("[4] Quit Menu\n\n\n");

  printf("Choose an option: ");

  int c=0,x=2;
  scanf("%d",&c);
  if(c==1)
  {
    char source[MAX_STR_SIZE], destination[MAX_STR_SIZE];
    printf("\n------------------------------------------\n");
    printf("Welcome to the enquiry page!\n");
    printf("------------------------------------------\n\n");
    printf("Please enter the name of the source location: ");
    scanf("%s",source);
    printf("Please enter the name of the destination location: ");
    scanf("%s",destination);
    printf("\n\n");
    x = enquiry(source,destination);
  }

  if(c==2)
  {
    char name[MAX_STR_SIZE], source[MAX_STR_SIZE], destination[MAX_STR_SIZE];
    printf("\n------------------------------------------\n");
    printf("Welcome to the booking page!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter the name of the source location: ");
    scanf("%s",source);
    printf("Please enter the name of the destination location: ");
    scanf("%s",destination);
    printf("\n\n");
    x = buyTicket(name,source,destination);
  }

  if(c==3)
  {
    int pnr;
    printf("\n------------------------------------------\n");
    printf("Welcome to the cancellation page!\n");
    printf("Please enter the PNR of the ticket you want cancelled: ");
    scanf("%d", &pnr);
    printf("\n\n");
    x = cancelTicket(pnr);
  }

  if(c==4)
  {
    printf("\n\n\nExiting the program!\n");
    return 0;
  }

  if(x)
  {
    printf("\n\n\nClosing the program as some problem occoured :(\n");
    return x;
  }

  printf("\nGoing back to the menu page...\n");
  showMenu();
}


int main()
{
  addTrain(1,"Delhi","Jaipur");
  addTrain(2,"Delhi","Mumbai");
  addTrain(3,"Delhi","Bangalore");
  addTrain(42,"Delhi","Antarctica");
  return showMenu();
}

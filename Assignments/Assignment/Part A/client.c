#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include "client.h"


void error(const char* msg)
{
	perror(msg);
	exit(1);
}

int main()
{
    int sockfd, portnum, n;
    struct sockaddr_in server_addr;
    char IP_ADDR[20] = "127.0.0.1";
    portnum = 16000;
    char inputbuf[MAX_INPUT_SIZE];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("SOCKET OPEN ERROR");
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    if(!inet_aton(IP_ADDR, &server_addr.sin_addr)) error("INVALID IP");
    server_addr.sin_port = htons(portnum);
    if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) error("CONNECTION ERROR");
    printf("Connected to server\n");
    do
    {
    	printf("Enter command: ");
    	bzero(inputbuf,MAX_INPUT_SIZE);
    	fgets(inputbuf,MAX_INPUT_SIZE-1,stdin);
  	  n = write(sockfd,inputbuf,strlen(inputbuf));
      if (n < 0) error("SOCKET WRITE ERROR");
    	bzero(inputbuf,MAX_INPUT_SIZE);
    	n = read(sockfd,inputbuf,(MAX_INPUT_SIZE-1));
    	if (n < 0) error("SOCKET READ ERROR");
    	printf("Server replied: %s\n",inputbuf);
    } while(strcmp(inputbuf, "Goodbye")!=0);
    return 0;
}

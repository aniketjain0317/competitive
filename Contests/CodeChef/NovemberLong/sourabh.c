#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct student STUDENT;
typedef struct student
{
  char name[MAX];
  int count;
  int length;
  STUDENT* next;
}  STUDENT;

STUDENT *addName(STUDENT* list, char* name)
{
  if(list==NULL)
  {
    list = (STUDENT* )malloc((sizeof(STUDENT)));
    strcpy(list->name,name);  list->count=1;  list->next=NULL;
    return list;
  }

  STUDENT* ptr = list;
  while(1)
  {
    if(!strcmp(ptr->name, name)) {  ptr->count++;  return list; }
    if(ptr->next==NULL) break;
    ptr=ptr->next;
  }

  STUDENT* newnode = (STUDENT* )malloc((sizeof(STUDENT)));
  ptr->next = newnode;
  strcpy(newnode->name,name);  newnode->count = 1;  newnode->next = NULL;
  return list;
}


int main()
{
  STUDENT* list = NULL;
  list = addName(list, "A");
  list = addName(list, "B");
  list = addName(list, "B");
  list = addName(list, "C");
  list = addName(list, "A");
}

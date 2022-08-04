#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 255
#define FILE_NAME "database.txt"
#define TEMP_NAME "database.tmp"

int insertKey(int key, char* value)
{
  FILE* fp = fopen(FILE_NAME, "a");
  char buff[BUFF_SIZE];
  int ch = getValue(key, buff);
  if(ch!=0) // i.e. No such key exists.
    fprintf(fp, "%d %s\n", key, value);
  fclose(fp);
  return !ch;
}

int getValue(int key, char* value)
{
  FILE* fp = fopen(FILE_NAME, "r");
  char line[BUFF_SIZE];
  int k, flag = 0;
  while (fgets(line, BUFF_SIZE, fp) != NULL)
  {
    sscanf(line, "%d %s", &k, value);
    if(k==key)
    {
      flag = 1;
      break;
    }
  }
  fclose(fp);
  return !flag;
}

int deleteKey(int key)
{
  FILE* fp = fopen(FILE_NAME, "r");
  FILE* tmp = fopen(TEMP_NAME, "w");
  char line[BUFF_SIZE], value[BUFF_SIZE];
  int k, flag = 0;
  while (fgets(line, BUFF_SIZE, fp) != NULL)
  {
    sscanf(line, "%d %s", &k, value);
    if(k==key) flag=1;
    else fprintf(tmp, "%d %s\n", k, value);
  }
  fclose(fp);
  fclose(tmp);
  remove(FILE_NAME);
  rename(TEMP_NAME, FILE_NAME);
  return !flag; // 0 -> OK;
}

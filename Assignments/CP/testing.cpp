#include <stdio.h>
#include <string.h>

int main()
{
  char str1[256];
  char str2[256];
  printf("Input Text: \n");
  gets(str1);
  printf("Search string: \n");
  gets(str2);
  int count = 0;
  const char *ptr = str1;
  while(true)
  {
    ptr = strstr(ptr, str2);
    if(!ptr) break;

    count++;
    ptr++;
  }
  printf("The number of occurrences of %s are %d\n", str2, count);
}

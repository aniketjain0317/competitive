#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

long long myAtoi(char* str)
{
    long long res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

int main()
{
  FILE* fp = freopen("10", "r", stdin);
  char str[256];
  printf("A\n");
  while(gets(str))
  {
    // const char delim[2] = {',','"'};
    printf("\n%s\n",str);
    char *token = strtok(str,",\"");
    printf("%lld\n", myAtoi(token));
    while(token!=NULL)
    {
      // printf("%s : ",token);
      token = strtok(NULL,",\"");
    }
  }
  fclose(fp);


  // insertionSort(cards, sorted_cards);

  return 0;
}

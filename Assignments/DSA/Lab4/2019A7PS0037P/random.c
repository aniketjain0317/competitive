#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int lower, int upper)
{
  return (rand() %(upper - lower + 1)) + lower;
}

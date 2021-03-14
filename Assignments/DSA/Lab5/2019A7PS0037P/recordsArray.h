#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "record.h"



struct recordsArray
{
  int INITIAL_CAPACITY;
  int GROWTH_FACTOR;

  struct record* array;
  int capacity;
  int size;
};

void init(struct recordsArray* cards);
int length(struct recordsArray* cards);
struct record get(struct recordsArray* cards, int pos);
void resize(struct recordsArray* cards);
void insert(struct recordsArray* cards, int pos, struct record x);
void append(struct recordsArray* cards, struct record x);
void printAllRecords(struct recordsArray* cards);
void printCardNumbers(struct recordsArray* cards);

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "recordsArray.h"

void init(struct recordsArray* cards)
{
  cards->INITIAL_CAPACITY = 16;
  cards->GROWTH_FACTOR = 2;
  cards->array = (struct record*) malloc(sizeof(struct record) * cards->INITIAL_CAPACITY);
  cards->capacity = cards->INITIAL_CAPACITY;
  cards->size = 0;
}

int length(struct recordsArray* cards)
{
  return cards->size;
}

struct record get(struct recordsArray* cards, int pos)
{
  assert(0 <= pos && pos < cards->size);
  return cards->array[pos];
}

void resize(struct recordsArray* cards)
{
  assert(cards->size==cards->capacity);
  cards->capacity *= cards->GROWTH_FACTOR;
  struct record* temp = (struct record*) realloc(cards->array, sizeof(struct record) * cards->capacity);
  cards->array = temp;
}

void insert(struct recordsArray* cards, int pos, struct record x)
{
  assert(0 <= pos && pos <= cards->size);
  if(cards->size==cards->capacity) resize(cards);

  struct record temp;
  for(int i=pos;i<=cards->size;i++)
  {
    temp = cards->array[i];
    cards->array[i]=x;
    x=temp;
  }
  cards->size++;
}

void append(struct recordsArray* cards, struct record x)
{
  insert(cards, cards->size, x);
}

void printAllRecords(struct recordsArray* cards)
{
  printf("\nALL CARDS: \n\n");
  for(int i=0; i< cards->size; i++)
  {
    printf("\n\t\tCARD NUMBER %d: \n", i+1);
    printRecord(cards->array[i]);
  }
}

void printCardNumbers(struct recordsArray* cards)
{
  printf("\nCARD NUMBERS: \n");
  for(int i=0; i< cards->size; i++) printf("%d: %lld\n", i+1, cards->array[i].card_no);
}

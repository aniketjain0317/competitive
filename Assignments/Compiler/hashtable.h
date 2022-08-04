#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include "hashtableDef.h"

int hash(char *key);
void initHashTable(hashTable);

int getHashValue(hashTable table, char *key, int isEmpty);

void insertHashTable(hashTable table, char *key, int value);
void insertPtrHashTable(hashTable table, char *key, void *value_ptr);
int searchHashTable(hashTable table, char *key);
void* searchPtrHashTable(hashTable table, char *key);
bool isKeyInHashTable(hashTable table, char *key);

#endif

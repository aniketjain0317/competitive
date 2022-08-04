#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *key) {
	int n = strlen(key);
  unsigned long hash_value = 5381;
  int c;
  while (c = *key++)
    hash_value = ((hash_value << 5) + hash_value) + c; // h = 33h+c;
	return hash_value % HASH_SIZE;
}

void initHashTable(hashTable table) {
	for (int i = 0; i < HASH_SIZE; i++)
	{
		table[i].present = false;
		table[i].value = NULL;
	}
}

void insertHashTable(hashTable table, char *key, int value) {
  int hashValue = getHashValue(table, key, GET_EMPTY);
  strncpy(table[hashValue].key, key, MAX_KEY_LEN);
	table[hashValue].present = true;
  table[hashValue].value = malloc(sizeof(int));
	*(int*)(table[hashValue].value) = value;
}

void insertPtrHashTable(hashTable table, char *key, void *value_ptr) {
	// printf("Inserting in hash table %s\n", key);
	int hashValue = getHashValue(table, key, GET_EMPTY);
	strncpy(table[hashValue].key, key, MAX_KEY_LEN);
	table[hashValue].present = true;
	table[hashValue].value = value_ptr;
}

int getHashValue(hashTable table, char* key, int getEmpty) {
  int hashValue = hash(key);
  for(int i = 1; table[hashValue].present; i++)
  {
    if(strcmp(table[hashValue].key, key) == 0) return hashValue;
    hashValue = (hashValue + i*i) % HASH_SIZE;
  }
  if(getEmpty) return hashValue;
  else return KEY_NOT_FOUND;
}

int searchHashTable(hashTable table, char *key) {
  int hashValue = getHashValue(table, key, !GET_EMPTY);
  if(hashValue == KEY_NOT_FOUND) return KEY_NOT_FOUND;
  return *(int*)(table[hashValue].value);
}

void* searchPtrHashTable(hashTable table, char *key) {
  int hashValue = getHashValue(table, key, !GET_EMPTY);
  if(hashValue == KEY_NOT_FOUND) return NULL;
  return table[hashValue].value;
}

bool isKeyInHashTable(hashTable table, char *key) {
  return getHashValue(table, key, !GET_EMPTY) != KEY_NOT_FOUND;
}

// int main()
// {
//   hashTable table;
//   initHashTable(table);
//   char *key = "abcde";
//   insertHashTable(table, key, 5);
//   int v = searchHashTable(table, key);
//   int b = isKeyInHashTable(table, key);
// 	printf("%d %d\n", v, b);
// }

#ifndef HASHTABLEDEF_H
#define HASHTABLEDEF_H

#define HASH_SIZE 67
#define MAX_KEY_LEN 100
#define KEY_NOT_FOUND -1
#define GET_EMPTY 1

typedef struct {
		char key[MAX_KEY_LEN];
		void *value;
		bool present;
} hashElement;

typedef hashElement hashTable[HASH_SIZE];

typedef struct symbol_table_wrapper{
	hashTable table;
	int level_num;
	struct symbol_table_wrapper *parent_table;
	struct symbol_table_wrapper *leftmost_child_table;
	struct symbol_table_wrapper *rightmost_child_table;
	struct symbol_table_wrapper *sibling_table;
}st_wrapper;

#endif

#ifndef DATABASE_H
#define DATABASE_H

#include "databaseDef.h"

int insertKey(int key, char* value);
int getValue(int key, char* value);
int deleteKey(int key);

#endif

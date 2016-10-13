#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H


#include "hash_table.h"

extern int (*hash_function)(HashTable*, int);

extern int hash_to_index(HashTable *table, int key);

extern int hash_naive(HashTable *table, int key);

extern int hash_TEST(HashTable *table, int key);

#endif

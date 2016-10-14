#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H


#include "hash_table.h"

#define DEFAULT_HASH_FUNCTION hash_mod_1000

extern int (*hash_function)(HashTable*, int);

extern int hash_to_index(HashTable *table, int key);

extern int hash_mod_1000(HashTable *table, int key);

extern int hash_mod_256(HashTable *table, int key);

extern int hash_mod_300(HashTable *table, int key);

#endif

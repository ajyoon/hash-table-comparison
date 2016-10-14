#include <stdio.h>

#include "hash_functions.h"
#include "hash_table.h"

int (*hash_function)(HashTable*, int) = DEFAULT_HASH_FUNCTION;

int hash_to_index(HashTable *table, int key) {
  return hash_function(table, key);
}

int hash_mod_1000(HashTable *table, int key) {
  int table_size = sizeof(*table) / sizeof(*table[0]);
  return (key % 1000) % table_size;
}

int hash_mod_256(HashTable *table, int key) {
  int table_size = sizeof(*table) / sizeof(*table[0]);
  return (key % 256) % table_size;
}

int hash_mod_300(HashTable *table, int key) {
  int table_size = sizeof(*table) / sizeof(*table[0]);
  return (key % 300) % table_size;
}

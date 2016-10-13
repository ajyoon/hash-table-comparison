#include <stdio.h>

#include "hash_functions.h"
#include "hash_table.h"

int (*hash_function)(HashTable*, int) = hash_naive;

int hash_to_index(HashTable *table, int key) {
  return hash_function(table, key);
}

int hash_naive(HashTable *table, int key) {
  int table_size = sizeof(*table) / sizeof(*table[0]);
  return (key % 1000) % table_size;
}

int hash_TEST(HashTable *table, int key) {
  int table_size = sizeof(*table) / sizeof(*table[0]);
  return (key % 243) % table_size;
}

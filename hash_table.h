#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

#include "linked_list.h"

#define TABLE_ARRAY_LEN 128


typedef ListNode* HashTable[TABLE_ARRAY_LEN];

bool insert_to_hash_table(HashTable *table, int key, int value);

ListNode* _find_node_in_hash_table(HashTable *table, int key);

int fetch_from_hash_table(HashTable *table, int key);

void remove_from_hash_table(HashTable *table, int key);

void free_table_and_chains(HashTable *table);

int count_collisions(HashTable *table);

float measure_sparsity(HashTable *table);

#endif

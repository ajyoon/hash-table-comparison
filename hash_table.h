#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"


typedef ListNode* HashTable[128];

extern int hash_key(int key);

extern int hash_to_index(int key, int table_len);

extern bool insert_to_hash_table(HashTable *table, int key, int value);

extern ListNode* _find_node_in_hash_table(HashTable *table, int key);

extern int fetch_from_hash_table(HashTable *table, int key);

extern bool remove_from_hash_table(HashTable *table, int key);

#endif

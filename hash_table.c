#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "hash_table.h"

// A naive hash function
int hash_key(int key)
{
  return key % 1000;
}

// Hash a key and return an index between 0 and `table_len`
// where the key should be placed in the table array
int hash_to_index(int key, int table_len)
{
  return (key % 1000) % table_len;
}

// A hash table of integers
typedef ListNode* HashTable[128];


// Insert a key,value pair into the hash table
// Returns true if a collision occurred, false if not
bool insert_to_hash_table(HashTable *table, int key, int value)
{
  // Calculate position in array based on hash table
  int array_index = hash_to_index(key, sizeof(*table) / sizeof(*table[0]));
  // Walk to end of collision (if one exists) and insert
  bool collision_occured = (*table[array_index] != NULL);
  *table[array_index] = insert(*table[array_index], -1, key, value);
  return collision_occured;
}

ListNode* _find_node_in_hash_table(HashTable *table, int key)
{
  // Calculate position in array based on hash table
  int array_index = hash_to_index(key, sizeof(*table) / sizeof(*table[0]));
  // Find and return value at key
  return _find_node_by_key(*table[array_index], key);
}

int fetch_from_hash_table(HashTable *table, int key)
{
  ListNode* found_node = _find_node_in_hash_table(table, key);
  if (found_node == NULL) {
    // Invalid look-up, return -1 (not good handling right now)
    return -1;
  }
  return found_node->value;
}

bool remove_from_hash_table(HashTable *table, int key)
{
  // Calculate position in array based on hash table
  int array_index = hash_to_index(key, sizeof(*table) / sizeof(*table[0]));

  *table[array_index] = delete_node_by_key(*table[array_index], key);
  return true;
}

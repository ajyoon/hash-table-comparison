#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "hash_table.h"
#include "hash_functions.h"


// Insert a key,value pair into the hash table
// Returns true if a collision occurred, false if not
bool insert_to_hash_table(HashTable *table, int key, int value)
{
  // Calculate position in array based on hash table
  int array_index = hash_to_index(table, key);
  // Walk to end of collision (if one exists) and insert
  bool collision_occured = (*table[array_index] != NULL);
  *table[array_index] = insert(*table[array_index], -1, key, value);
  return collision_occured;
}

// Retrieve a ListNode* from the table given a key
ListNode* _find_node_in_hash_table(HashTable *table, int key)
{
  // Calculate position in array based on hash table
  int array_index = hash_to_index(table, key);
  // Find and return value at key
  return _find_node_by_key(*table[array_index], key);
}

// Retrieve the value stored at `key` in a table
int fetch_from_hash_table(HashTable *table, int key)
{
  ListNode* found_node = _find_node_in_hash_table(table, key);
  if (found_node == NULL) {
    // Invalid look-up, return -1 (not good handling right now)
    return -1;
  }
  return found_node->value;
}

// Remove the value stored at `key` in a table
void remove_from_hash_table(HashTable *table, int key)
{
  // Calculate position in array based on hash table
  int array_index = hash_to_index(table, key);
  *table[array_index] = delete_node_by_key(*table[array_index], key);
}

// Free the memory for an entire table, including all nodes in
// any linked lists it contains
void free_table_and_chains(HashTable *table)
{
  int table_size = sizeof(*table) / sizeof(*table[0]);
  for (int i = 0; i < table_size; i++) {
    ListNode *chain_node = *table[i];
    ListNode *del_node = chain_node;
    while (del_node != NULL) {
      chain_node = chain_node->next;
      free(del_node);
      del_node = chain_node;
    }
  }
  free(table);
}

// Count the number of collisions present in a table
int count_collisions(HashTable *table)
{
  int table_size = sizeof(*table) / sizeof(*table[0]);
  int collision_count = 0;
  for (int i = 0; i < table_size; i++) {
    if (*table[i] == NULL || (*table[i])->next == NULL) {
      // No collision here
      continue;
    }
    // Collision found
    ListNode* current_node = (*table[i]);
    while (current_node->next != NULL) {
      collision_count++;
      current_node = current_node->next;
    }
  }
  return collision_count;
}

// Return a float 0 - 1 measure of how sparse a table's primary
// array is, where 0 is completely full and 1 is completely sparse (empty)
float measure_sparsity(HashTable *table)
{
  int table_size = sizeof(*table) / sizeof(*table[0]);
  int null_count = 0;
  for (int i = 0; i < table_size; i++) {
    if ((*table[i]) == NULL) {
      null_count++;
    }
  }
  return (float)null_count / (float)table_size;
}

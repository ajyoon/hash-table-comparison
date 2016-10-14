#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "hash_table.h"
#include "hash_functions.h"


#define TEST_FUNCTION(hash_function_name)       \
  test_function(hash_function_name, #hash_function_name)


void test_function(int (*hash_func)(HashTable*, int), char func_name[])
{
  // Save global hash function to revert at the end
  int (*old_hash_func)(HashTable*, int) = hash_func;

  printf("Testing function \"%s\"...\n", func_name);
  hash_function = hash_func;

  // Generate random test table
  HashTable *test_table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));

  int item_count = TABLE_ARRAY_LEN / 2;
  int collision_count = 0;
  for (int i = 0; i < item_count; i++) {
    collision_count += insert_to_hash_table(test_table, rand(), rand());
  }
  printf("%d collisions occurred with %d items across a table of length %d.\n",
         collision_count, item_count, TABLE_ARRAY_LEN);

  free_table_and_chains(test_table);

  hash_function = old_hash_func;
  return;
}


int main(int argc, char *argv[])
{
  srand(time(NULL));

  TEST_FUNCTION(hash_mod_1000);
  TEST_FUNCTION(hash_mod_256);
  TEST_FUNCTION(hash_mod_300);

  return 0;
}

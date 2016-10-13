#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "hash_table.h"
#include "hash_functions.h"


void test_function(int (*hash_func)(HashTable*, int), char func_name[])
{
  // Save global hash function to revert at the end
  int (*old_hash_func)(HashTable*, int) = hash_func;

  printf("Testing function \"%s\"...\n", func_name);
  hash_function = hash_func;

  // Generate random test table
  HashTable *test_table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));

  int collision_count = 0;
  int key;
  for (int i = 0; i < 10; i++) {
    key = rand();
    collision_count += insert_to_hash_table(test_table, i, 853);
  }
  printf("%d collisions occurred with 5000 items\n", collision_count);

  free_table_and_chains(test_table);

  hash_function = old_hash_func;
  return;
}


int main(int argc, char *argv[])
{
  srand(time(NULL));

  test_function(hash_naive, "hash_naive");
  test_function(hash_TEST, "hash_TEST");

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "linked_list.h"
#include "hash_table.h"


int main(int argc, char *argv[])
{
  srand(time(NULL));
  HashTable *test_table = malloc(sizeof(HashTable));
  int collision_count = 0;
  int key;
  for (int i = 0; i < 5000; i++) {
    key = rand();
    collision_count += insert_to_hash_table(test_table, key, 853);
  }

  printf("%d collisions occurred with 5000 items\n", collision_count);

  return 0;
}

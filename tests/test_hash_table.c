#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#include "../linked_list.h"
#include "../hash_table.h"
#include "../hash_functions.h"
#include "test_hash_table.h"


int hash_mock_constant_value_0(HashTable *table, int key)
{
  return 0;
}

int hash_mock_constant_value_1(HashTable *table, int key)
{
  return 1;
}

int hash_mock_constant_value_2(HashTable *table, int key)
{
  return 2;
}

void _setup_hash_func(int (*hash_func)(HashTable*, int))
{
  hash_function = hash_func;
}

void _teardown_hash_func()
{
  hash_function = DEFAULT_HASH_FUNCTION;
}

bool test_insert_to_hash_table_without_collision()
{
  _setup_hash_func(hash_mock_constant_value_0);

  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  bool collision_occurred = insert_to_hash_table(table, 1, 2);
  assert(collision_occurred == false);

  free_table_and_chains(table);
  _teardown_hash_func();
  return true;
}

bool test_insert_to_hash_table_with_collision()
{
  _setup_hash_func(hash_mock_constant_value_0);

  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  insert_to_hash_table(table, 1, 2);
  bool collision_occurred = insert_to_hash_table(table, 3, 4);
  assert(collision_occurred == true);

  free_table_and_chains(table);
  _teardown_hash_func();
  return true;
}

bool test_insert_to_hash_table_key_is_stored()
{
  _setup_hash_func(hash_mock_constant_value_0);

  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  insert_to_hash_table(table, 1, 2);
  assert((*table[0])->key == 1);

  free_table_and_chains(table);
  _teardown_hash_func();
  return true;
}

bool test_insert_to_hash_table_value_is_stored()
{
  _setup_hash_func(hash_mock_constant_value_0);

  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  insert_to_hash_table(table, 1, 2);
  assert((*table[0])->value == 2);

  free_table_and_chains(table);
  _teardown_hash_func();
  return true;
}

bool test_count_collisions()
{
  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  _setup_hash_func(hash_mock_constant_value_0);
  insert_to_hash_table(table, 1, 2);
  insert_to_hash_table(table, 2, 2);  // Create collision at index 0
  _setup_hash_func(hash_mock_constant_value_1);
  insert_to_hash_table(table, 1, 2);
  insert_to_hash_table(table, 2, 2);  // Create collision at index 1

  assert(count_collisions(table) == 2);

  free_table_and_chains(table);
  _teardown_hash_func();
  return true;
}

bool test_measure_sparsity()
{
  _setup_hash_func(hash_mock_constant_value_0);
  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  insert_to_hash_table(table, 1, 2);

  float epsilon = 0.001;  // Float comparison leeway
  float expected = ((float)TABLE_ARRAY_LEN - 1.0) / (float)(TABLE_ARRAY_LEN);
  assert(fabsf(measure_sparsity(table) - expected) < epsilon);

  free_table_and_chains(table);
  _teardown_hash_func();
  return true;
}

bool test_free_table_and_chains()
{
  // Does not currently test that chain linked lists were freed!
  HashTable *table = calloc(TABLE_ARRAY_LEN, sizeof(ListNode));
  _setup_hash_func(hash_mock_constant_value_0);
  insert_to_hash_table(table, 1, 2);
  insert_to_hash_table(table, 2, 2);  // Create collision at index 0
  insert_to_hash_table(table, 2, 2);  // Create second collision at index 0
  _setup_hash_func(hash_mock_constant_value_1);
  insert_to_hash_table(table, 1, 2);
  insert_to_hash_table(table, 2, 2);  // Create collision at index 1

  free_table_and_chains(table);
  assert(table == NULL);

  _teardown_hash_func();
  return true;

}

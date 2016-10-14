#ifndef TEST_HASH_TABLE_H
#define TEST_HASH_TABLE_H

#include <stdbool.h>

bool test_insert_to_hash_table_without_collision();
bool test_insert_to_hash_table_with_collision();
bool test_insert_to_hash_table_key_is_stored();
bool test_insert_to_hash_table_value_is_stored();
bool test_count_collisions();
bool test_measure_sparsity();

#endif

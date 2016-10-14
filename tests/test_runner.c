#include <stdio.h>
#include <stdlib.h>

#include "test_linked_list.h"
#include "test_hash_table.h"

#define INIT_TESTS()   \
  int test_count = 0;  \
  int pass_count = 0

#define RUN_TEST(testname)          \
  test_count += 1;                  \
  pass_count += testname() ? 1 : 0

int main()
{
  INIT_TESTS();

  RUN_TEST(test_insert_existing_with_null_head);
  RUN_TEST(test_insert_existing_inside_list);
  RUN_TEST(test_insert_existing_at_end_with_explicit_index);
  RUN_TEST(test_insert_existing_at_end_with_neg_1_index);
  RUN_TEST(test_insert_existing_at_end_with_neg_1_index_and_len_1_list);
  RUN_TEST(test_insert_head_is_preserved);
  RUN_TEST(test_insert_key_is_stored);
  RUN_TEST(test_insert_value_is_stored);
  RUN_TEST(test_delete_head);
  RUN_TEST(test_delete_middle);
  RUN_TEST(test_delete_end);
  RUN_TEST(test_delete_end_with_neg_1_index);
  RUN_TEST(test_delete_end_with_neg_1_index_and_len_1_list);
  RUN_TEST(test_find_value_by_key_at_head);
  RUN_TEST(test_find_value_by_key_at_middle);
  RUN_TEST(test_find_value_by_key_at_end);
  RUN_TEST(test_find_value_by_key_with_invalid_key);
  RUN_TEST(test_find_value_by_index_at_head);
  RUN_TEST(test_find_value_by_index_at_middle);
  RUN_TEST(test_find_value_by_index_at_end);
  RUN_TEST(test_find_value_by_index_with_invalid_index);
  RUN_TEST(test_find_value_by_index_with_neg_1_index);
  RUN_TEST(test_find_value_by_index_with_neg_1_index_and_len_1);
  RUN_TEST(test_find_node_by_key_at_head);
  RUN_TEST(test_find_node_by_key_at_middle);
  RUN_TEST(test_find_node_by_key_at_end);
  RUN_TEST(test_find_node_by_key_with_invalid_key);
  RUN_TEST(test_insert_to_hash_table_without_collision);
  RUN_TEST(test_insert_to_hash_table_with_collision);
  RUN_TEST(test_insert_to_hash_table_key_is_stored);
  RUN_TEST(test_insert_to_hash_table_value_is_stored);
  RUN_TEST(test_count_collisions);
  RUN_TEST(test_measure_sparsity);


  printf("%d total tests run: %d passed, %d failed.\n",
         test_count, pass_count, test_count - pass_count);

  return 0;
}

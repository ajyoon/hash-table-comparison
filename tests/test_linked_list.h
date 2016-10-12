#ifndef TEST_LINKED_LIST_H
#define TEST_LINKED_LIST_H

#include <stdbool.h>

bool test_insert_existing_with_null_head();
bool test_insert_existing_inside_list();
bool test_insert_existing_at_end_with_explicit_index();
bool test_insert_existing_at_end_with_neg_1_index();
bool test_insert_existing_at_end_with_neg_1_index_and_len_1_list();
bool test_insert_head_is_preserved();
bool test_insert_key_is_stored();
bool test_insert_value_is_stored();
bool test_delete_head();
bool test_delete_middle();
bool test_delete_end();
bool test_delete_end_with_neg_1_index();
bool test_delete_end_with_neg_1_index_and_len_1_list();
bool test_find_value_by_key_at_head();
bool test_find_value_by_key_at_middle();
bool test_find_value_by_key_at_end();
bool test_find_value_by_key_with_invalid_key();
bool test_find_value_by_index_at_head();
bool test_find_value_by_index_at_middle();
bool test_find_value_by_index_at_end();
bool test_find_value_by_index_with_invalid_index();
bool test_find_value_by_index_with_neg_1_index();
bool test_find_value_by_index_with_neg_1_index_and_len_1();
bool test_find_node_by_key_at_head();
bool test_find_node_by_key_at_middle();
bool test_find_node_by_key_at_end();
bool test_find_node_by_key_with_invalid_key();

#endif

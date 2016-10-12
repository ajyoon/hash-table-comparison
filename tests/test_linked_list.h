#ifndef TEST_LINKED_LIST_H
#define TEST_LINKED_LIST_H

#include <stdbool.h>

bool test_insert_existing_with_null_head();
bool test_insert_existing_inside_list();
bool test_insert_existing_at_end_with_explicit_index();
bool test_insert_existing_at_end_with_neg_1_index();
bool test_insert_head_is_preserved();
bool test_insert_key_is_stored();
bool test_insert_value_is_stored();
bool test_delete_head();
bool test_delete_middle();
bool test_delete_end();
bool test_delete_end_with_neg_1_index();
bool test_delete_end_with_neg_1_index_and_len_1_list();
bool test_insert_existing_at_end_with_neg_1_index_and_len_1_list();

#endif

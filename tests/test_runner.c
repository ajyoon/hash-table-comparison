#include <stdio.h>
#include <stdlib.h>

#include "test_linked_list.h"

int main()
{
  int test_count = 0;
  int pass_count = 0;

  test_count += 1;
  pass_count += test_insert_existing_with_null_head() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_existing_inside_list() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_existing_at_end_with_explicit_index() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_existing_at_end_with_neg_1_index() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_head_is_preserved() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_key_is_stored() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_value_is_stored() ? 1 : 0;

  test_count += 1;
  pass_count += test_delete_head() ? 1 : 0;

  test_count += 1;
  pass_count += test_delete_middle() ? 1 : 0;

  test_count += 1;
  pass_count += test_delete_end() ? 1 : 0;

  test_count += 1;
  pass_count += test_delete_end_with_neg_1_index() ? 1 : 0;

  test_count += 1;
  pass_count += test_delete_end_with_neg_1_index_and_len_1_list() ? 1 : 0;

  test_count += 1;
  pass_count += test_insert_existing_at_end_with_neg_1_index_and_len_1_list() ? 1 : 0;


  printf("%d total tests run: %d passed, %d failed.\n",
         test_count, pass_count, test_count - pass_count);

  return 0;
}

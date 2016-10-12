#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "../linked_list.h"
#include "test_linked_list.h"
#include "test_utils/utils.h"


bool test_insert_existing_with_null_head()
{
  ListNode* head = NULL;
  ListNode* insert_node = malloc(sizeof(ListNode));
  ListNode* new_head = insert_existing(head, 0, insert_node);
  assert(new_head != NULL);
  assert(new_head == insert_node);
  assert(new_head->next == NULL);
  free(insert_node);
  return true;
}

bool test_insert_existing_inside_list()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* end = malloc(sizeof(ListNode));
  head->next = end;
  end->next = NULL;

  ListNode* insert_node = malloc(sizeof(ListNode));
  ListNode* new_head = insert_existing(head, 1, insert_node);

  assert(new_head == head);
  assert(head->next == insert_node);
  assert(insert_node->next == end);
  assert(end->next == NULL);

  free(head);
  free(end);
  free(insert_node);
  return true;
}

bool test_insert_existing_at_end_with_explicit_index()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* second = malloc(sizeof(ListNode));
  head->next = second;
  second->next = NULL;

  ListNode* insert_node = malloc(sizeof(ListNode));
  insert_node->next = NULL;
  ListNode* new_head = insert_existing(head, 2, insert_node);

  assert(new_head == head);
  assert(head->next == second);
  assert(second->next == insert_node);
  assert(insert_node->next == NULL);

  free(head);
  free(second);
  free(insert_node);
  return true;
}

bool test_insert_existing_at_end_with_neg_1_index()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* second = malloc(sizeof(ListNode));
  head->next = second;
  second->next = NULL;

  ListNode* insert_node = malloc(sizeof(ListNode));
  insert_node->next = NULL;
  ListNode* new_head = insert_existing(head, -1, insert_node);

  assert(new_head == head);
  assert(head->next == second);
  assert(second->next == insert_node);
  assert(insert_node->next == NULL);

  free(head);
  free(second);
  free(insert_node);
  return true;
}

bool test_insert_existing_at_end_with_neg_1_index_and_len_1_list()
{
  ListNode* head = NULL;
  ListNode* insert_node = malloc(sizeof(ListNode));
  insert_node->next = NULL;
  ListNode* new_head = insert_existing(head, -1, insert_node);

  assert(new_head == insert_node);
  assert(new_head->next == NULL);

  free(new_head);
  return true;
}


bool test_insert_head_is_preserved()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* new_head = insert(head, 1, 5, 6);
  assert(head == new_head);

  free(head->next);
  free(head);
  return true;
}

bool test_insert_key_is_stored()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* new_head = insert(head, 1, 5, 6);
  assert(new_head->next->key == 5);

  free(head->next);
  free(head);
  return true;
}

bool test_insert_value_is_stored()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* new_head = insert(head, 1, 5, 6);
  assert(new_head->next->value == 6);

  free(head->next);
  free(head);
  return true;
}

bool test_delete_head()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* second = malloc(sizeof(ListNode));
  ListNode* third = malloc(sizeof(ListNode));
  head->next = second;
  second->next = third;

  ListNode* new_head = delete_node(head, 0);

  assert(new_head == second);

  free(second);
  free(third);
  return true;
}

bool test_delete_middle()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* second = malloc(sizeof(ListNode));
  ListNode* third = malloc(sizeof(ListNode));
  head->next = second;
  second->next = third;

  ListNode* new_head = delete_node(head, 1);

  assert(new_head == head);
  assert(head->next == third);

  free(head);
  free(third);
  return true;
}

bool test_delete_end()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* second = malloc(sizeof(ListNode));
  ListNode* third = malloc(sizeof(ListNode));
  third->next = NULL;
  head->next = second;
  second->next = third;

  ListNode* new_head = delete_node(head, 2);

  assert(new_head == head);
  assert(head->next == second);
  assert(second->next == NULL);

  free(head);
  free(second);
  return true;
}

bool test_delete_end_with_neg_1_index()
{
  ListNode* head = malloc(sizeof(ListNode));
  ListNode* second = malloc(sizeof(ListNode));
  ListNode* third = malloc(sizeof(ListNode));
  head->next = second;
  second->next = third;
  third->next = NULL;

  ListNode* new_head = delete_node(head, -1);

  assert(new_head == head);
  assert(head->next == second);
  assert(second->next == NULL);

  free(head);
  free(second);
  return true;
}

bool test_delete_end_with_neg_1_index_and_len_1_list()
{
  ListNode* head = malloc(sizeof(ListNode));
  head->next = NULL;

  ListNode* new_head = delete_node(head, -1);

  assert(new_head == NULL);
  return true;
}

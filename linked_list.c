#include <stdlib.h>

#include "linked_list.h"

/* Insert an existing node into a linked list.
Args:

    ListNode* head: The head of the linked list
    int index: The 0-based index in the list where the node
        will be inserted. -1 Signifies the end of the list.
    ListNode* insert_node: An existing node (initialized except
        for insert_node->next)

Returns:
    ListNode*: the head of the linked list. If `index == 0`, this will
        be different than the input `head`
 */
ListNode* insert_existing(ListNode* head, int index, ListNode* insert_node)
{
  // Special case for inserting at index 0
  if (index == 0 || (index == -1 && (head == NULL || head->next == NULL))) {
    if (head != NULL) {
      insert_node->next = head;
    }
    return insert_node;
  }
  // Seek the node immediately before the insertion point
  ListNode* current_node = head;
  if (index == -1) {
    // index of -1 means insert at the end
    while (current_node != NULL && current_node->next != NULL) {
      current_node = current_node->next;
    }
  } else {
    for (int i = 0; i < index - 1; i++) {
      current_node = current_node->next;
    }
  }
  if (current_node->next != NULL) {
    insert_node->next = current_node->next;
  }
  current_node->next = insert_node;
  return head;
}

/* Create and insert a new node into a linked list.

   Args:
       ListNode* head: The head of the linked list
       int index: The 0-based index in the list where the node
           will be inserted. -1 Signifies the end of the list.
       int key: the key of the new node (this can be any valid `int`)
       int value: the value of the list item

   Returns:
       ListNode*: the head of the linked list. If `index == 0`, this will
               be different than the input `head`
*/
ListNode* insert(ListNode* head, int index, int key, int value)
{
  ListNode *new_node = malloc(sizeof(ListNode));
  new_node->key = key;
  new_node->value = value;
  new_node->next = NULL;
  return insert_existing(head, index, new_node);
}

/* Delete an item from the list at a given index.

   If the only remaining node in the list is being deleted,
   a NULL pointer is returned.

   Args:
       ListNode* head: The head of the linked list
       int index: The 0-based index in the list where a node
           will be deleted. -1 Signifies the end of the list.

   Returns:
       ListNode*: the head of the linked list. If `index == 0`, this will
           be different than the input `head`.
*/
ListNode* delete_node(ListNode* head, int index) {
  // Special case if an empty list is passed
  if (head == NULL) {
    return NULL;
  }
  // Special case for deleting at index 0
  if (index == 0 || (index == -1 && head->next == NULL)) {
    ListNode* new_head = head->next;
    free(head);
    return new_head;
  }
  // Seek the node immediately before the deletion point
  ListNode* current_node = head;
  if (index == -1) {
    // index of -1 means delete at the end
    while (current_node != NULL && current_node->next->next != NULL) {
      current_node = current_node->next;
    }
  } else {
    for (int i = 0; i < index - 1; i++) {
      current_node = current_node->next;
    }
  }
  // Relink surrounding node(s) and free memory
  ListNode* delete_node = current_node->next;
  if (current_node->next->next == NULL) {
    current_node->next = NULL;
  } else {
    current_node->next = current_node->next->next;
  }
  free(delete_node);
  return head;
}

// Delete a node by its key. Return the head of the list.
ListNode* delete_node_by_key(ListNode* head, int key) {
  // Empty list
  if (head == NULL) {
    return NULL;
  }
  // Lists of length 1
  if (head->next == NULL) {
    if (head->key == key) {
      free(head);
      return NULL;
    }
    return head;
  }
  // Longer lists
  ListNode* current_node = head;
  while (1) {
    if (current_node->next->key == key || current_node->next == NULL) {
      break;
    }
    current_node = current_node->next;
  }
  if (head->next->key != key) {
    // Key wasn't found - nothing to do here...
    return head;
  }
  // Relink surrounding node(s) and free memory
  ListNode* delete_node = current_node->next;
  if (current_node->next->next == NULL) {
    current_node->next = NULL;
  } else {
    current_node->next = current_node->next->next;
  }
  free(delete_node);
  return head;
}


// Retrieve the value of the node in a linked list with a given key.
// If no such node exists, return -1
int find_value_by_key(ListNode* head, int key)
{
  ListNode* current_node = head;
  while (1) {
    if (current_node == NULL) {
      return -1;
    }
    if (current_node->key == key) {
      return current_node->value;
    }
    current_node = current_node->next;
  }
}

// Retrieve the value of the node in a linked list at a given index.
// if index == -1, get the value of the last item in the list.
// if the given index is invalid, return -1.
int find_value_by_index(ListNode* head, int index)
{
  ListNode* current_node = head;
  if (index == -1) {
    while (current_node != NULL && current_node->next != NULL) {
      current_node = current_node->next;
    }
  } else{
    for (int i = 0; i < index; i++) {
      if (current_node == NULL) {
        return -1;
      }
      current_node = current_node->next;
    }
  }
  if (current_node == NULL) {
    return -1;
  }
  return current_node->value;
}

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/* A singly linked list with nodes containing
   an integer key and value for use in hash table
   collision chaining */
typedef struct _ListNode {
  int key;
  int value;
  struct _ListNode* next;
} ListNode;

extern ListNode* insert_existing(ListNode* head, int index, ListNode* insert_node);

extern ListNode* insert(ListNode* head, int index, int key, int value);

extern ListNode* delete_node(ListNode* head, int index);

extern ListNode* delete_node_by_key(ListNode* head, int key);

extern int find_value_by_key(ListNode* head, int key);

extern int find_value_by_index(ListNode* head, int index);

#endif

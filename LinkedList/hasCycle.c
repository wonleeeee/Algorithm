#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// https://leetcode.com/problems/linked-list-cycle/

// Node struct for linked list
struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Struct for hash table
struct info {
    struct ListNode *cur;
    struct info *next;
} info;

// Fuctions for linked list

struct ListNode *create_node(int val) {
    struct ListNode *newnode;
    newnode = malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

struct ListNode *insert_to_head(struct ListNode **head, struct ListNode *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

// Space complexity : O(1) 220104
bool hasCycle(struct ListNode *head) {

    if (!head || !head->next) return false;

    struct ListNode *slow, *fast;
    
    slow = head;
    fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Time complexity : O(n) - store nodes to hash table
/*
bool hasCycle(struct ListNode *head) {

    return false;
}
*/

int main() {
    int i, pos=1;
    bool output;
    int nums[] = {3,2,0,-4};
    struct ListNode *tmp, *end, *head=NULL;

    for (i=3; i>=0; i--) {
        tmp = create_node(nums[i]);
        insert_to_head(&head, tmp);
        if (i==pos) {
            end = tmp;
        }
    }
    while (tmp->next!=NULL) {
        tmp = tmp->next;
    }
    tmp->next = end;

    output = hasCycle(head);
    printf("%d\n", output);
    
    return 0;
}
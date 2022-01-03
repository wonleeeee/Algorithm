#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// https://leetcode.com/problems/reverse-linked-list/

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *create_node(int val) {
    struct ListNode *tmp;
    tmp = malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}

struct ListNode *insert_into_head(struct ListNode **head, struct ListNode *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void free_node(struct ListNode *head) {
    struct ListNode *tmp;
    tmp = head;
    while (tmp != NULL) {
        head = tmp->next;
        free(tmp);
        tmp = head;
    }
}


// Iterative function 220103
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *tmp, *newhead=NULL;

    if (head == NULL) return NULL;    

    tmp = head;
    
    while (tmp != NULL) {
        head = tmp->next;
        insert_into_head(&newhead, tmp);
        tmp = head;
    }

    return newhead;
}


// Recursive function
/*
struct ListNode *reverseList(struct ListNode *head) {
    return NULL;
}
*/

int main() {
    struct ListNode *head = NULL, *tmp;
    int i;

    // Input : 1 - 2 - 3 - 4 - 5
    for (i=5; i>=1; i--) {
        tmp = create_node(i);
        insert_into_head(&head, tmp);
    }
    tmp = reverseList(head);
    while (tmp != NULL) {
        printf("%d - ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
    free_node(tmp);
    head = NULL;
    tmp = NULL;

    // Input : 1 - 2
    for (i=2; i>=1; i--) {
        tmp = create_node(i);
        insert_into_head(&head, tmp);
    }
    tmp = reverseList(head);
    while (tmp != NULL) {
        printf("%d - ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
    free_node(tmp);
    head = NULL;
    tmp = NULL;

}
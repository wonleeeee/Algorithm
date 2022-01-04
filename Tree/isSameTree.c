#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// 220104
// https://leetcode.com/problems/same-tree/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create_node(int val) {
    struct TreeNode *result = malloc(sizeof(struct TreeNode));
    result->left = NULL;
    result->right = NULL;
    result->val = val;
    return result;
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    bool left, right;
    
    if (!p && !q) return true;
    else if ((!p && q) | (p && !q)) return false;
    if (p->val != q->val) return false;

    left = isSameTree(p->left, q->left);
    right = isSameTree(p->right, q->right);

    return (left & right);
}

int main() {
    bool result;
    struct TreeNode *n1, *n2, *n3, *m1, *m2, *m3;

    n1 = create_node(1);
    n2 = create_node(2);
    n3 = create_node(3);
    m1 = create_node(1);
    m2 = create_node(2);
    m3 = create_node(3);

    n1->left = n2;
    n1->right = n3;
    m1->left = m2;
    m1->right = m3;

    result = isSameTree(n1, m1);
    printf("Result : %i\n", result);

    return 0;
}
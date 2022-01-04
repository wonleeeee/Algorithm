#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// 220104
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

int maxDepth(struct TreeNode *root) {

    if (root == NULL) return 0;
    if (!root->left && !root->right) return 1;

    int ld=0, rd=0;

    ld = maxDepth(root->left) + 1;
    rd = maxDepth(root->right) + 1;

    if (ld > rd) return ld;
    else return rd;
}

int main() {
    int result;
    struct TreeNode *n1, *n2, *n3, *n4, *n5;

    n1 = create_node(3);
    n2 = create_node(9);
    n3 = create_node(20);
    n4 = create_node(15);
    n5 = create_node(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    result = maxDepth(n1);
    printf("Max Depth: %d\n", result);

    return 0;
}
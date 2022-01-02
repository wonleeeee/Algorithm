#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// https://leetcode.com/problems/contains-duplicate/

typedef struct info {
    int num;
    struct info *next;
} info;

// Simple hash function
int hash(int num, int numsSize) {
    int hash_value = num % numsSize;
    if (hash_value < 0) {
        hash_value += numsSize;
    }
    return hash_value;
}

bool containsDuplicate(int *nums, int numsSize) {

    int i, index;

    info *tmp, *hash_table[numsSize], *newNode;

    // Initialize hash table
    for (i=0; i<numsSize; i++) {
        hash_table[i] = NULL;
    }

    for (i=0; i<numsSize; i++) {
        index = hash(nums[i], numsSize);
        tmp = hash_table[index];

        // Return if finds same value in hash table
        while (tmp != NULL && tmp->num!=nums[i]) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            // Free all malloced memory
            for (i=0; i<numsSize; i++) {
                tmp = hash_table[i];
                while (tmp!=NULL) {
                    hash_table[i] = tmp;
                    tmp = tmp->next;
                    free(hash_table[i]);
                }
            }
            return true;
        }

        // If not found insert to the hash table
        newNode = malloc(sizeof(info));
        newNode->num = nums[i];
        newNode->next = hash_table[index];
        hash_table[index] = newNode;
    }

    return false;
}

int main() {
    int nums1[] = {1,2,3,1};
    int numsSize1 = 4;
    bool result = containsDuplicate(nums1, numsSize1);

    printf("1: %d\n", result);

    int nums2[] = {1,2,3,4};
    int numsSize2 = 4;
    result = containsDuplicate(nums2, numsSize2);

    printf("2: %d\n", result);

    int nums3[] = {1,1,1,3,3,4,3,2,4,2};
    int numsSize3 = 10;
    result = containsDuplicate(nums3, numsSize3);

    printf("3: %d\n", result);

    int nums4[] = {1,5,-2,-4,0};
    int numsSize4 = 5;
    result = containsDuplicate(nums4, numsSize4);

    printf("4: %d\n", result);
}
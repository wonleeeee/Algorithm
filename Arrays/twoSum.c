#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// https://leetcode.com/problems/two-sum/

typedef struct info {
    int num;
    int pos;
    struct info *next;
} info;

unsigned int hash(int num, int numsSize) {

    unsigned int hash_value;

    hash_value = num % numsSize;

    return hash_value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int i, index, *returnVal;
    info *tmp, *newNode;

    // Construct hash table size of numsSize
    info *hash_table[numsSize];
    returnVal = malloc(*returnSize*sizeof(int));

    // Initialize hash table and set to NULL
    for (i=0; i<numsSize; i++) {
        hash_table[i] = NULL;
    }

    // Search through an input array
    for (i=0; i<numsSize; i++) {
        
        index = hash(target-nums[i], numsSize);
        tmp = hash_table[index];

        // Look up the hash table
        while (tmp!=NULL && tmp->num!=(target-nums[i])) {
            tmp = tmp->next;
        }

        // Return position if found
        if (tmp != NULL) {
            returnVal[0] = tmp->pos;
            returnVal[1] = i;

            // Free malloced hash table
            for (i=0; i<numsSize; i++) {
                tmp = hash_table[i];
                while (tmp!=NULL) {
                    hash_table[i] = tmp;
                    tmp = tmp->next;
                    free(hash_table[i]);
                }
            }
            return returnVal;
        }

        // Add to the hash table, if it does not exists
        index = hash(nums[i], numsSize);
        newNode = malloc(sizeof(info));
        newNode->num = nums[i];
        newNode->pos = i;
        newNode->next = hash_table[index];
        hash_table[index] = newNode;
    }

    return NULL;
}

int main() {
    int numsSize, target, *returnArray, returnSize;
    int nums1[] = {2, 7, 11, 15};
    int nums2[] = {3,2,4};
    int nums3[] = {3,3};

    numsSize = 4;
    target = 9;
    returnSize = 2;

    returnArray = twoSum(nums1, numsSize, target, &returnSize);

    printf("nums1 : [2, 7, 11, 15],\ntarget : %d -> %i, %i\n", target, returnArray[0], returnArray[1]);

    free(returnArray);

    numsSize = 3;
    target = 6;
    returnSize = 2;

    returnArray = twoSum(nums2, numsSize, target, &returnSize);

    printf("nums2 : [3,2,4],\ntarget : %d -> %i, %i\n", target, returnArray[0], returnArray[1]);

    free(returnArray);

    numsSize = 2;
    target = 6;
    returnSize = 2;

    returnArray = twoSum(nums3, numsSize, target, &returnSize);

    printf("nums3 : [3, 3],\ntarget : %d -> %i, %i\n", target, returnArray[0], returnArray[1]);

    free(returnArray);

    return 0;
}
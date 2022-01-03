#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// https://leetcode.com/problems/product-of-array-except-self/

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i, tmp, left=1, right=1;
    int leftArray[numsSize];
    int *return_value = malloc(*returnSize*sizeof(int));

    for (i=0; i<numsSize; i++) {
        left *= nums[i];
        leftArray[i] = left;
    }

    for (i=numsSize-1; i>=0; i--) {
        tmp = right;
        right *= nums[i];

        if (i!=0) {
            return_value[i] = tmp * leftArray[i-1];
        }
        else {
            return_value[i] = tmp;
        }
    }

    return return_value;
}

int main() {

    int i;
    int nums1[] = {1,2,3,4};
    int numsSize = 4;
    int returnSize = 4;
    int *returnArray1;

    returnArray1 = productExceptSelf(nums1, numsSize, &returnSize);

    printf("Input : [1,2,3,4]\nOutput : ");
    for (i=0; i<returnSize; i++) {
        printf("%d ", returnArray1[i]);
    }
    printf("\n");

    int nums2[] = {-1,1,0,-3,3};
    numsSize = 5;
    returnSize = 5;
    int *returnArray2;

    returnArray2 = productExceptSelf(nums2, numsSize, &returnSize);

    printf("Input : [1,2,3,4]\nOutput : ");
    for (i=0; i<returnSize; i++) {
        printf("%d ", returnArray2[i]);
    }
    printf("\n");
}
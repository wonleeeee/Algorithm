#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// 220105
// https://leetcode.com/problems/climbing-stairs/

uint8_t doesInit = 1;
uint8_t initialN;
int *nums;

void init_hash_table(int n) {
    int i;
    nums = malloc(n*sizeof(int));
    for (i=0; i<n; i++) {
        nums[i] = 0;
    }
}

int climbStairs(int n) {
    if (n==2) return 2;
    else if (n==1) return 1;

    int result;

    if (doesInit) {
        initialN = n;
        init_hash_table(n);
        doesInit = 0;
    }

    if (!nums[n-1]) {
        nums[n-1] = climbStairs(n-1);
    }
    if (!nums[n-2]) {
        nums[n-2] = climbStairs(n-2);
    }

    if (initialN == n) {
        doesInit = 1;
        result = nums[n-1] + nums[n-2];
    }

    free(nums);

    return result;
}



int main() {
    int n = 4;
    printf("n=2 : %d\n", climbStairs(n));
    n=45;
    printf("n=45 : %d\n", climbStairs(n));
    return 0;
}
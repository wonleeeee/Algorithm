#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// 220105
// https://leetcode.com/problems/coin-change/

int coinChange(int *coins, int coinsSize, int amount) {

    if (amount == 0) return 0;

    int i, result;

    for (i=1; i<=coinsSize; i++) {
        if (amount-coins[coinsSize-i] >= 0) {
            result = coinChange(coins, coinsSize, amount-coins[coinsSize-i]);
            if (result == -1) {
                return result;
            }
            return result + 1;
        }
    }
    return -1;
}

int main() {
    int coins1[] = {1,2,5}, coins2[] = {2}, coins3[] = {1};
    int coinsSize = 3, amount = 11;
    printf("%d\n", coinChange(coins1, coinsSize, amount));

    coinsSize = 1;
    amount = 3;
    printf("%d\n", coinChange(coins2, coinsSize, amount));

    coinsSize = 1;
    amount = 0;
    printf("%d\n", coinChange(coins3, coinsSize, amount));

    return 0;
}
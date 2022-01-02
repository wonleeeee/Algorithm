#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize) {
    int i, start, end, max, curMax;

    start = 0;
    end = 0;
    max = 0;
    curMax = 0;

    for (i=0; i<pricesSize; i++) {
        if (prices[start] > prices[i]) {
            start = i;
            end = i;
        }
        else if (prices[end] < prices[i]) {
            end = i;
            curMax = prices[end] - prices[start];
            if (max < curMax) {
                max = curMax;
            }
        }
    }

    return max;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int prices2[] = {7, 6, 4, 3, 1};
    int pricesSize1 = 6;
    int pricesSize2 = 5;
    int result;

    result = maxProfit(prices1, pricesSize1);
    printf("[7, 1, 5, 3, 6, 4] : %i\n", result);

    result = maxProfit(prices2, pricesSize2);
    printf("[7, 6, 4, 3, 1] : %i\n", result);

    return 0;
}
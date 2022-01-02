#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize) {
    uint16_t i;
    uint32_t best[pricesSize];

    for (i=0; i<pricesSize; i++) {
        
    }

    return 0;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = 6;
    int result;

    result = maxProfit(prices, pricesSize);

    printf("%i", result);

    return 0;
}
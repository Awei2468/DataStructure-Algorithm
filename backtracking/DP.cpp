#include "memory.h"

const int capacity = 8;

struct Item {
    char name[20];
    int weight;
    int price;
};

int dp[capacity + 1] = {0};

int Knapsack_1(Item *fruit, int *value, bool *track, int length, int limit) {
    int i, w;
    for (i = 0; i < length; ++i) {
        for (w = fruit[i].weight; w <= limit; ++w) {
            int newValue = value[w - fruit[i].weight] + fruit[i].price;
            value[w] = (newValue > value[w]) ? newValue : value[w];
            if (value[w] == newValue)
                *(track + i*(capacity+1) + w) = true;
        }
    }
    return value[limit];
}

int Knapsack_2(Item *fruit, int *value, int length, int limit) {
    for (int i = 0; i < length; ++i) {
        for (int w = limit; w >= fruit[i].weight; --w) {  //using backward method can only comsume one dimension array space
            int newValue = value[w - fruit[i].weight] + fruit[i].price;
            value[w] = (newValue > value[w]) ? newValue : value[w];
        }
    }
    return value[limit];
}


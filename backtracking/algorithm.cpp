#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include "memory.h"

using namespace std;

#define KNAPASK_PROBLEM         true
#define DYNAMIC_PROGRAMMING     false
#define DIVIDE_CONQUER          false
#define BACK_TRACKING           false
#define GREEDY                  false
#define BRANCH_BOUND            false

#if (KNAPASK_PROBLEM)
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
#endif // (KNAPASK_PROBLEM)

#if (BACK_TRACKING)
    #define MAXQUEEN 8

    class Queen {
        private:
            int queen[MAXQUEEN];
            int total_solution = 0;
        public:
            void place(int q);
            int attack(int row, int col);
            void solution(void);
    };

    void Queen::place(int q) {
        int i = 0;
        while (i < MAXQUEEN) {
            if (!attack(i, q)) {
                queen[q] = i;   //row position
                if (q == MAXQUEEN-1)
                    solution();
                else
                    place(q+1);
            }
            ++i;
        }
    }

    int Queen::attack(int row, int col) {
        int i = 0, offset_row, offset_col;
        bool atk = false;
        while (!atk && i < col) {   //曾經true就結束
            offset_col = abs(i - col);
            offset_row = abs(queen[i] - row);
            atk = ((queen[i] == row) || (offset_row == offset_col));
            ++i;
        }
        return atk;
    }

    void Queen::solution(void) {
        total_solution += 1;
        cout << "solution #" << setw(3) << total_solution << endl;
        for (int i = 0; i < MAXQUEEN; ++i) {
            for (int j = 0; j < MAXQUEEN; ++j) {
                if (i == queen[j])
                    cout << "Q";
                else
                    cout << "-";
            }
            cout << endl;
        }
    }
#endif // (BACK_TRACKING)

int main(){

#if (KNAPASK_PROBLEM)
    Item fruit[] = {{"Apple", 4, 4500},
                    {"Banana", 5, 5700},
                    {"Orange", 2, 2250},
                    {"Watermelon", 1, 1100},
                    {"Strawberry", 6, 6700}
                   };
    int length = sizeof(fruit) / sizeof(fruit[0]);
    bool record[length][capacity + 1];
    memset(record, false, sizeof(record));

    cout << "Maximum value: " << Knapsack_1(fruit, dp, &record[0][0], length, capacity) << endl;
    for (int i = length-1, j = capacity; i >= 0; --i) {   //backward
        if (record[i][j]) {
            cout << fruit[i].name << "(index:" << i << ")" << " in the knapask." << endl;
            j -= fruit[i].weight;
        }
    } 

    cout << "Maximum value: " << Knapsack_2(fruit, dp, length, capacity) << endl;

#endif // (KNAPASK_PROBLEM)
    
#if (BACK_TRACKING)
    Queen obj;
    obj.place(0);
#endif // (BACK_TRACKING)

    system("pause");
    return 0;
}
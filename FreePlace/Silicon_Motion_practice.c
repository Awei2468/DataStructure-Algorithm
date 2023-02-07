#include<stdio.h>
#include<stdlib.h>

#define USING_METHOD 1
int Calculate(int last_value);

int main() {

    //calculate: 1 + 2 + 4 + 7 + 11 + ... + 106
    printf("sum = %d\n", Calculate(106));

    system("pause");
    return 0;
}

int Calculate(int last_value) {
#if (USING_METHOD == 1)
    //method 1
    int *dp = (int *)calloc(last_value + 1, sizeof(int));
    int sum;
    sum = dp[0] = 1;
    for (int i = 1; i < last_value + 1; ++i) {
        dp[i] = dp[i-1] + i;
        sum += dp[i];
        if (dp[i] == last_value) break;
    }
    free(dp);
    return sum;
#elif (USING_METHOD == 2)
    //method 2
    int pre = 1, cur, sum = 1;
    for (int i = 1; i < last_value; ++i) {
        cur = pre + i;
        sum += cur;
        pre = cur;
        if (cur == last_value) break;
    }
    return sum;
#else
#endif    
}
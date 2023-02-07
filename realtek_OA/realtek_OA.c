#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>

int Sum(int *arr, int n);

int main() {


    //1 + 2 + 4 + 7 + 11 + …，假設此數列有n個數值，用C語言將數列總和算出來，並列出n=1, 2, 3, 4, 5的執行結果。
    int arr1[100] = {0};
    printf("n = 1, result = %d\n", Sum(arr1, 1));
    printf("n = 2, result = %d\n", Sum(arr1, 2));
    printf("n = 3, result = %d\n", Sum(arr1, 3));
    printf("n = 4, result = %d\n", Sum(arr1, 4));
    printf("n = 5, result = %d\n", Sum(arr1, 5));

    system("pause");
    return 0;
}

int Sum(int *arr, int n) {
    arr[0] = 1;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        arr[i] = arr[i-1] + i - 1;
        count += arr[i];
    }
    //n = 1, arr[1] = arr[0] + 1 = 1 + 0 = 1, count = 1 
    //n = 2, arr[2] = arr[1] + 1 = 1 + 1 = 2, count = 1 + 2 = 3
    //n = 3, arr[3] = arr[2] + 2 = 2 + 2 = 4, count = 3 + 4 = 7
    //n = 4, arr[4] = arr[3] + 3 = 4 + 3 = 7, count = 7 + 7 = 14
    //n = 5, arr[5] = arr[4] + 4 = 7 + 4 = 11, count = 14 + 11 = 25
    return count;
}

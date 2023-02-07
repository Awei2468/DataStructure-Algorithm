#include<stdio.h>
#include<stdlib.h>

void Print_Array(int *arr, int n);
int *PROBLEM_1(int *a, int n);
bool PROBLEM_2(int x);
void Selection_Sort(int *arr, int n);
void Quick_Sort(int *arr, int l, int r);
void swap1(int *a, int *b);
void swap2(int &a, int &b);
int Max_Bit_Position(int x);
bool Binary_Search(int *arr, int l, int r, int target);
int FindFirstZeroPosition(int *arr, int len);
int PureBinarySearch(int *arr, int len, int target);

#define FIND_MAX_VALUE(x, y, mask) (x & mask) > (y & mask) ? (x & mask) : (y & mask)
#define FIND_MIN_VALUE(x, y, mask) (x & mask) > (y & mask) ? (y & mask) : (x & mask)

int main() {

    //problem_1
    int array1[] = {0, 1, 0, 2, 4, 0, 6, 0, 0}, n1 = sizeof(array1) / sizeof(array1[0]);
    int *ptr1 = (int *)calloc(n1, sizeof(int));
    ptr1 = PROBLEM_1(array1, n1);
    Print_Array(ptr1, n1);

    //problem_2
    int x1 = 11;
    if (PROBLEM_2(x1))
        printf("true\n");
    else
        printf("false\n");

    //Sorting(selection sort)
    int array2[] = {10, 1, 9, 5, 8, 2, 7, 4, 3, 6}, n2 = sizeof(array2) / sizeof(array2[0]);
    Selection_Sort(array2, n2);
    Print_Array(array2, n2);

    //Sorting(quick sort)
    int array3[] = {10, 1, 9, 5, 8, 2, 7, 4, 3, 6}, n3 = sizeof(array3) / sizeof(array3[0]);
    Quick_Sort(array3, 0, n3-1);
    Print_Array(array3, n3);

    //Binary Search
    int x2 = 7;
    if (Binary_Search(array3, 0, n3-1, x2)) printf("%d, Exist\n", x2);
    else printf("%d, Not exist\n", x2);

    x2 = 11;
    if (Binary_Search(array3, 0, n3-1, x2)) printf("%d, Exist\n", x2);
    else printf("%d, Not exist\n", x2);

    //max bit position
    int x3 = 8;
    printf("%d\n", Max_Bit_Position(x3));

    //a+b+c = 10, list all possible answers
    for (int a = 0; a <= 10; ++a) {
        for (int b = 0; b <= 10; ++b) {
            for (int c = 0; c <= 10; ++c) {
                if (a + b + c == 10) {
                    printf("%d + %d + %d = 10\n", a, b, c);
                }
            }
        }
    }

    //2022/01/05 phison interview
    int array4[] = {1,1,1,1,1,1,0,0,0}, n4 = sizeof(array4) / sizeof(array4[0]);
    printf("position:%d\n", FindFirstZeroPosition(array4, n4));

    int x4 = 0x3, x5 = 0x5, mask = 0x7;
    printf("result1 = %x\n", FIND_MAX_VALUE(++x4,x5--,mask));
    printf("result2 = %x\n", FIND_MIN_VALUE(x4--,++x5,mask));
    printf("result3 = %x\n", FIND_MAX_VALUE(++x4,x5,mask));

    //pure binary search
    int array5[] = {2,4,6,8,10}, n5 = sizeof(array5) / sizeof(array5[0]);
    int x6 = 11;
    if (PureBinarySearch(array5, n5, x6) >= 0)
        printf("%d can be found!\n", x6);
    else
        printf("%d can't be found!\n", x6);

    system("pause");
    return 0;
}

void Print_Array(int *arr, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int *PROBLEM_1(int *a, int n) {
    int j = n-1;
    for (int i = n-1; i >= 0; --i) {
        if (!a[i]) continue;
        a[j--] = a[i];
    }
    for (int i = 0; i <= j; ++i)
        a[i] = 0;
    return a;
}

bool PROBLEM_2(int x) {
    while (x) {
        if ((x & 3) == 3) return true;
        x >>= 1;
    }
    return false;
}

void Selection_Sort(int *arr, int n) {  //O(n^2)
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                /*
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                */
                swap1(&arr[i], &arr[j]);
            }
        }
    }
}

void Quick_Sort(int *arr, int l, int r) {  //O(nlogn)
    if (l >= r) return;
    int j = l - 1, tmp;
    for (int i = l; i < r; ++i) {
        if (arr[i] < arr[r]) {
            ++j;
            /*
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            */
            swap2(arr[i], arr[j]);
        }
    }
    ++j;
    /*
    tmp = arr[j];
    arr[j] = arr[r];
    arr[r] = tmp;
    */
    swap2(arr[j], arr[r]);
    Quick_Sort(arr, l, j-1);
    Quick_Sort(arr, j+1, r);
}

void swap1(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int Max_Bit_Position(int x) {
    int cnt = 1, Max = -1;
    while (x) {
        if (x & 1)
            Max = cnt;
        ++cnt;
        x >>= 1;
    }
    return Max;
}

bool Binary_Search(int *arr, int l, int r, int target) {
    while (l <= r) {
        int m = l + ((r-l) >> 1);
        if (arr[m] > target)
            r = m - 1;
        else if (arr[m] < target)
            l = m + 1;
        else
            return true;
    }
    return false;
}

int FindFirstZeroPosition(int *arr, int len) {
    int l = 0, r = len-1;
    while (r > 0 && l <= r) {
        int m = l + ((r-l) >> 1);
        if (arr[m])
            l = m+1;
        else
            r = m-1;
    }
    return r+1;
}

int PureBinarySearch(int *arr, int len, int target) {  //左閉右開
    int l = 0, r = len;
    while (l < r) {
        int m = l + ((r-l) >> 1);
        if (target <= arr[m])
            r = m;
        else
            l = m+1;
    }
    return l >= len ? -1 : arr[l] == target ? l : -1;
}
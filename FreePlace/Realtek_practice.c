#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

struct Test {
    int num;
    char *name;
    short date;
    char ch[2];
    short st[4];
}*p;

long ByteSwap(long x);

int main() {

    //problem1
    int arr1[5] = {1,2,3,4,5};
    int *ptr1 = (int *)(&arr1 + 1);
    printf("%d,%d\n", *(arr1 + 1), *(ptr1 - 1)); //2,5

    //problem2
    p = (struct Test*)0x10000;
    printf("%p\n", p + 0x1);  //0x10014
    printf("%p\n", (unsigned long)p + 0x1);  //0x10001
    printf("%p\n", (unsigned int*)p + 0x1);  //0x10004
    printf("sizeof p->name: %d\n", sizeof(p->name));  //4, 指標大小固定是4 byte
    printf("sizeof p: %d\n", sizeof(p));  //4, 指標大小固定是4 byte

    //problem3
    int arr2[4] = {1,2,3,4};
    int *ptr2 = (int *)(&arr2 + 1);
    int *ptr3 = (int *)((int)arr2 + 1);
    printf("%x , %x\n", ptr2[-1], *ptr3); //4 , 2000000

    //problem4
    int arr3[3][2] = {{0,1}, {2,3}, {4,5}};
    int *ptr4 = arr3[0];
    printf("%d\n", ptr4[0]); //0

    //problem5
    long x1 = 0x12345678;
    printf("After swap %x : %x\n", x1, ByteSwap(x1));

    system("pause");
    return 0;
}

long ByteSwap(long x) {
    long res = 0;
    while (x) {
        res <<= 8;
        res |= x & 0xFF;
        x >>= 8;
    }
    return res;
}
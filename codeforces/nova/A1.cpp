#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define N 5
int main(){
    int a[N] = {9,6,5,4,1},i,temp;
    for (int i = 0; i < N/2; ++i) {
        temp=a[i];
        a[i]=a[N-i-1];
        a[N-i-1]=temp;
    }
    for (int i = 0; i < N; ++i)
        printf("%4d",a[i]);
    return 0;
    printf("\n");
}
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void f1(int *z, int y) {
    int x;
    x=5;
    *z=x-y;
    printf("%d %d\n",*z,y);
}
void f2(int *x,int *y) {
    f1(x,2);
    f1(y,*x);
}
int main(){
    int x,y;
    f2(&x,&y);
    printf("%d %d\n",x,y);
    return 0;
}
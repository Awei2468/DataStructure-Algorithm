#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    unsigned a,b,c,d;
    a=0x8;
    b=a>>1;
    c=~(~0<<1);
    d=b&c;
    printf("c is %d\n",c);
    printf("d is %d\n",d);
    return 0;
}
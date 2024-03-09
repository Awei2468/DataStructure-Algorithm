#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void function2(int *a,int *b,int *c) { //指標帶入function變數時為複製一個指標來存，只有間接運算子(*)會改變本尊的值，assign位址並不會影響本尊位址
    int *temp=a;
    //printf("1.a=%x b=%x c=%x\n",a,b,c);
    *b=(*c)*(*temp),*c=*temp,*a=10,a=b,b=c,c=temp;
    //printf("2.a=%x b=%x c=%x\n",a,b,c);
}

int main(){
    int i=-1,j=4,k=2,*p=&i,*q=&j,*x=&k;

    function2(p,q,&k);
    //printf("i=%x j=%x k=%x\n",&i,&j,&k);
    //printf("p=%x q=%x x=%x\n",p,q,x);
    printf("%d %d %d\n",i,j,k);
    return 0;
}
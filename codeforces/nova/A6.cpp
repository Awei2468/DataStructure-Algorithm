#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int x = 5;
void a(void) { //local varibale
    int x=20;
    x += 5;
    //printf("xa=%x\n",&x);
    printf("%d ", x);
}
void b(void) { //static variable
    static int x = 30;
    x += 5;
    //printf("xb=%x\n",&x);
    printf("%d ", x);
}
void c(void) { //global variable
    x += 5;
    //printf("xc=%x\n",&x);
    printf("%d ", x);
}
int main(){
    int x = 1; //local variable
    //printf("xm=%x\n",&x);
    printf("%d\n", x);
    a();
    b();
    c();
    printf("%d\n", x);
    a();
    b();
    c();
    printf("%d\n", x);
}

//https://www.geeksforgeeks.org/memory-layout-of-c-program/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void func1(int **a, int *b, int *c) {
    
    **a += 10;
    *b += 5;
    *c *= 7;
    b = c; //不影響
    *a = b; //不影響
    a = &b; //不影響
    printf("**a=%x *a=%x b=%x c=%x\n",a,*a,b,c);
}

int main(){
    int x=10, y=25, z=5, *px=&x;
    
    printf("(1)x=%x y=%x z=%x px=%x\n",&x,&y,&z,&px);

    func1(&px,&y,&z);

    printf("(2)x=%x y=%x z=%x px=%x\n",&x,&y,&z,&px);
    printf("x=%d y=%d z=%d\n",x,y,z);
    return 0;
}
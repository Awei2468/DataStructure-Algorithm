#include<bits/stdc++.h>
#include<iostream>

using namespace std;

char* function1(char *a, int i) {
    a+=i;return a;
}
int main(){
    char a1[]={'a','b','c'},a2[]={'d','e','f'},*p1=a1+2,*p2=a2;
    int i;

    printf("%c %c\n",*p1,*(p2+1));
    for (i=0; i<2; ++i) {
        p2=function1(p1,i);
        printf("%c \n",*p2);
    }
    printf("%c\n",'z'-1);
    printf("\n");
    return 0;
}
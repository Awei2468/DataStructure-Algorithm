#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    int resp[10]={1,2,3,2,1,3,2,1,2,2};
    int freq[10]={0};
    int ivar=-999, ino, temp;
    for (ino=0;ino<10;ino++){
        temp = ++freq[resp[ino]];
        if(ivar<temp) ivar=temp;
        printf("%d ", ivar);
    }
    printf("\n");
    return 0;
}
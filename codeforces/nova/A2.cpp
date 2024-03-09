#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    int a = 0;
    int b = 0;
    {
        int b = 1;
        {
            int n = 1;
            printf("%d%d\n",a,b);
        }
        {
            int b = 2;
            printf("%d%d\n",a,b);
        }
        printf("%d%d\n",a,b);
    }
    printf("%d%d\n",a,b);
}
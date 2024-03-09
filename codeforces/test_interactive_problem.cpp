#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int l = 1, r = 1e6+1;
    while (l < r) {
        int m = l+(r-l)/2;
        printf("%d\n", m);
        fflush(stdout);

        char response[3];
        scanf("%s", response);
        if (strcmp(response, "<") == 0) r = m;
        else l = m+1;
    }

    printf("! %d\n", l-1);
    fflush(stdout);

    return 0;
}
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int res = 0;
    char g[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin>>g[i][j];
        }
    }

    //1
    for (int j = 0; j < 10; ++j) {
        if (g[0][j]=='X') res += 1;
        if (g[9][j]=='X') res += 1;
    }
    for (int i = 1; i < 9; ++i) {
        if (g[i][0]=='X') res += 1;
        if (g[i][9]=='X') res += 1;
    }

    //2
    for (int j = 1; j < 9; ++j) {
        if (g[1][j]=='X') res += 2;
        if (g[8][j]=='X') res += 2;
    }
    for (int i = 2; i < 8; ++i) {
        if (g[i][1]=='X') res += 2;
        if (g[i][8]=='X') res += 2;
    }

    //3
    for (int j = 2; j < 8; ++j) {
        if (g[2][j]=='X') res += 3;
        if (g[7][j]=='X') res += 3;
    }
    for (int i = 3; i < 7; ++i) {
        if (g[i][2]=='X') res += 3;
        if (g[i][7]=='X') res += 3;
    }

    //4
    for (int j = 3; j < 7; ++j) {
        if (g[3][j]=='X') res += 4;
        if (g[6][j]=='X') res += 4;
    }
    for (int i = 4; i < 6; ++i) {
        if (g[i][3]=='X') res += 4;
        if (g[i][6]=='X') res += 4;
    }

    //5
    for (int j = 4; j < 6; ++j) {
        if (g[4][j]=='X') res += 5;
        if (g[5][j]=='X') res += 5;
    }
    
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}
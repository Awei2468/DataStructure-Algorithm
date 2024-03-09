#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    char tbl[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>tbl[i][j];
        }
    }

    bool e[3] = {false};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tbl[i][j] == '?') {
                for (int j = 0; j < 3; ++j) {
                    if (tbl[i][j] == '?') continue;
                    e[tbl[i][j]-'A'] = true;
                }
                break;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (!e[i]) cout << (char)('A'+i) << endl;
    }
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
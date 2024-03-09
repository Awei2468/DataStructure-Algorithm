#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    string s;
    cin>>s;

    int a = 0, b = 0;
    for (char &c : s) {
        if (c == 'A') ++a;
        else ++b;
    }

    if (a > b) cout << 'A' << endl;
    else cout << 'B' << endl;
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
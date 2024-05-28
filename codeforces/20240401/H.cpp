#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    bool res = 1;
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i]) {
            res = 0;
            break;
        }
    }
    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
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
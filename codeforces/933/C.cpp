#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, res = 0;
    cin>>n;
    string s;
    cin>>s;

    for (int i = 0; i <= n-3; ++i) {
        string sub = s.substr(i,3);
        if (sub == "map" || sub == "pie") ++res, i+=2;
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
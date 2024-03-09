#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, b1 = -1, b2 = -1;
    cin>>n;
    string s;
    cin>>s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            if (b1 == -1) b1 = i;
            b2 = i;
        }
    }

    cout << b2-b1+1 << endl;
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
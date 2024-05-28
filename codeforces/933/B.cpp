#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n;
    cin>>n;
    int v[n];

    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    for (int i = 0; i <= n-3; ++i) {
        if (v[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        else {
            v[i+1] -= (v[i]<<1);
            v[i+2] -= v[i];
            v[i] = 0;
        }
    }

    if (v[n-1] || v[n-2]) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
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
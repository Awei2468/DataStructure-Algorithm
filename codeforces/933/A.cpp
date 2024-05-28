#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, m , k, res = 0;
    cin>>n>>m>>k;
    int b[1001], c[1001];

    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>c[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i]+c[j] <= k) ++res;
        }
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
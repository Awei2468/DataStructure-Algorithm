#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, a, b, res = INT_MAX;
    cin>>n>>a>>b;

    for (int i = 0; i*2 <= n; ++i) {
        res = min(res,  b*i+(n-2*i)*a);
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
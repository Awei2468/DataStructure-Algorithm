#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,char> pr;

void solve() {
    ULL res = 0;
    int n, m;
    cin>>n>>m;
    LL vn[n], vm[m];
    for (int i = 0; i < n; ++i) cin>>vn[i];
    for (int i = 0; i < m; ++i) cin>>vm[i];

    sort(vn, vn+n);
    sort(vm, vm+m);

    for (int i = 0; i < n; ++i) {
        res += max(abs(vn[i]-vm[m-1-i]), abs(vn[i]-vm[n-1-i]));
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
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, m, k, res = 0;
    cin>>n>>m>>k;
    int va[n], vb[m];

    for (int i = 0; i < n; ++i) {
        cin>>va[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>vb[i];
    }
    map<int,int> cnt;
    for (int i = 0; i < m; ++i) {
        ++cnt[vb[i]];
    }

    int good = 0;
    for (int i = 0; i < m-1; ++i) {
        good += cnt[va[i]]-- > 0;
    }
    for (int i = 0; i <= n-m; ++i) {
        good += cnt[va[i+m-1]]-- > 0;
        if (good >= k) ++res;
        good -= ++cnt[va[i]] > 0;
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
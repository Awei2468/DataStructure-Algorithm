#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n;
    cin>>n;
    int vec[n], pre[n];
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    }

    pre[n-1] = n;
    for (int i = n-2; i >= 0; --i) {
        pre[i] = vec[i]==vec[i+1] ? pre[i+1] : i+1;
    }

    int q;
    cin>>q;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin>>l>>r;
        --l;
        if (pre[l] < r) cout << l+1 << " " << pre[l]+1 << endl;
        else cout << -1 << " " << -1 << endl;
    }
    cout << endl;
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
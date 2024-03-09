#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, q;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    cin>>q;

    for (int i = 0; i < q; ++i) {
        int l, k;
        cin>>l>>k;
        int t = a[l-1], r = -1;
        for (int j = l-1; j < n; ++j) {
            t &= a[j];
            if (t >= k) r = max(r, j);
            if (!t) break;
        }
        if (r == -1) cout << r << " ";
        else cout << r+1 << " ";
    }
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
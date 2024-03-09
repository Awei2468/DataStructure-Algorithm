#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    
    unordered_map<int,int> hash1, hash2;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        ++hash1[x];
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin>>x;
        ++hash2[x];
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= k; ++i) {
        bool find = 0;
        if (hash1.find(i) != hash1.end()) ++cnt1, find = 1;
        if (hash2.find(i) != hash2.end()) ++cnt2, find = 1;
        if (!find) {
            cout << "NO" << endl;
            return;
        }
    }

    if (cnt1 < k/2 || cnt2 < k/2) cout << "NO" << endl;
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
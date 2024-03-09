#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

ULL cal(vector<int>&v, int m) {
    ULL res = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (m-v[i]>0) res+=(m-v[i]);
    }
    return res;
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin>>v[i];
    int l = 1, r = 2e9+1;
    while (l < r) {
        int m = l+(r-l)/2;
        if (cal(v, m) <= x)
            l=m+1;
        else r=m; 
    }

    cout << l-1 << endl;
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
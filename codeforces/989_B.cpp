#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, mi = 100;
    cin>>n;
    vector<int> v(n);
    ULL res = 1;

    for (int i = 0 ; i < n; ++i) {
        cin>>v[i];
        mi = min(mi,v[i]);
    }
    bool first = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i]!=mi) res *= v[i];
        else {
            if (!first) res *= (v[i]+1), first = 1;
            else res *= v[i];
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
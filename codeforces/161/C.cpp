#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,int> pr;
typedef array<int,3> ay;

void solve() {
    int n, m;
    cin>>n;
    int x[n];

    for (int i = 0; i < n; ++i) cin>>x[i];
    cin>>m;

    ULL dpl[n], dpr[n];
    dpl[0] = 0, dpl[1] = 1;
    for (int i = 1; i < n-1; ++i) {
        if (x[i+1]-x[i] < x[i]-x[i-1]) dpl[i+1] = dpl[i]+1;
        else dpl[i+1] = dpl[i]+x[i+1]-x[i];
        //cout << "dpl[i+1]=" << dpl[i+1] << endl;
    }

    dpr[n-1] = 0, dpr[n-2] = 1;
    for (int i = n-2; i > 0; --i) {
        if (x[i+1]-x[i] < x[i]-x[i-1]) dpr[i-1] = dpr[i]+x[i]-x[i-1];
        else dpr[i-1] = dpr[i]+1;
        //cout << "dpr[i-1]=" << dpr[i-1] << endl;
    }

    for (int i = 0; i < m; ++i) {
        int s, e;
        cin>>s>>e;
        --s, --e;
        if (s < e) cout << dpl[e]-dpl[s] << endl;
        else cout << dpr[e]-dpr[s] << endl;
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
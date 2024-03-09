#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    ULL res = 0;
    int n;
    cin>>n;
    int e[n];

    for (int i = 0; i < n; ++i) cin>>e[i];
    if (n < 3) {
        cout << 0 << endl;
        return;
    }

    sort(e, e+n);

    for (int i = 0; i < n; ++i) {
        
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
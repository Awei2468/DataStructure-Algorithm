#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long LL;
typedef pair<int,char> pr;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> va(n);

    for (int i = 0; i < n; ++i) cin>>va[i];

    long t = 0;
    for (int i = 0; i < m; ++i) {
        int b;
        cin>>b;
        t |= b;
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        x ^= va[i];
        y ^= (va[i]|t);
    }

    if (x > y) swap(x,y);
    cout << x << " " << y << endl;
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
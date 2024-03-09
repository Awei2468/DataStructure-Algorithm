#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n;
    cin>>n;
    ULL sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        sum += a;
    }
    if ((ULL)(sqrt(sum)*100000000) % 100000000 == 0.0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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
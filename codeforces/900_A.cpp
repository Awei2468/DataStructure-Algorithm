#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, k;
    cin>>n>>k;
    bool pass = false;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        if (x == k) {
            pass = true;
        }
    }
    if (pass) cout << "YES" << endl;
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
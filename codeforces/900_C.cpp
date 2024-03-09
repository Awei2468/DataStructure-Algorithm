#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    ULL n, k, x, lsum, ssum;
    cin>>n>>k>>x;

    lsum = (n+(n-k+1))*k/2;
    ssum = (1+k)*k/2;
    if (lsum < x || ssum > x) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
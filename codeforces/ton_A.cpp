#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long LL;
typedef pair<int,char> pr;

void solve() {
    int n, k, x;
    cin>>n>>k>>x;
    if (k > n || k-x > 1) {
        cout << -1 << endl;
        return;
    }
    if (k == x) cout << k*(k-1)/2+(k-1)*(n-k) << endl;
    else cout << k*(k-1)/2+x*(n-k) << endl;
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
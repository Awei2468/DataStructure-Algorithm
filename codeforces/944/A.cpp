#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
   int x, y;
   cin>>x>>y;
   cout << min(x,y) << " " << max(x,y) << endl; 
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
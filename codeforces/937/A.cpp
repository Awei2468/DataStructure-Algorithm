#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int a, b, c;
    cin>>a>>b>>c;
    if (a<b && b<c) cout << "STAIR" << endl;
    else if (a<b && b>c) cout << "PEAK" << endl;
    else cout << "NONE" << endl;
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
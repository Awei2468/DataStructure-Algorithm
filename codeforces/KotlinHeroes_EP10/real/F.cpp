#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() { //1208. Get Equal Substrings Within Budget
    int n = s.size(), res = 0, l = 0, r = 0, dif = 0;
    while (r < n) {
        dif += abs(s[r]-t[r]);
        ++r;
        while (l < r && dif > maxCost) {
            dif -= abs(s[l]-t[l]);
            ++l;
        }
        res = max(res, r-l);
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
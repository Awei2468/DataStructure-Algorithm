#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    LL n, k, sum = 0, res = 0;
    cin>>n>>k;
    int life[n];

    for (int i = 0; i < n; ++i) {
        cin>>life[i];
        sum += life[i];
    }
    if (k >= sum) {
        cout << n << endl;
        return;
    }
    
    LL h = k>>1;
    LL left, right;
    if (k&1) {
        left = h+1, right = h;
    }
    else {
        left = h, right = h; 
    }

    int l = 0, r = n-1;
    for (; l < r; ) {
        bool go = 0;
        if (left >= life[l]) left -= life[l++], ++res, go = 1;
        if (right >= life[r]) right -= life[r--], ++res, go = 1;
        if (!go) break;
    }

    if (l == r) {
        if (left > 0 && left >= life[l]) ++res;
        else if (right > 0 && right >= life[r]) ++res; 
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
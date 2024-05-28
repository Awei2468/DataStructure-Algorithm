#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    LL n, c, d, small = LLONG_MAX;
    LL sum = 0;
    cin>>n>>c>>d;
    map<LL,LL> mp;

    for (int i = 0; i < n*n; ++i) {
        LL t;
        cin>>t;
        small=min(small,t);
        sum += t;
        mp[t]++;
    }

    sum -= (c+d)*n*(n-1)*n/2;
    if (sum%(n*n) || sum/(n*n) != small) {
        cout << "NO" << endl;
        return;
    }
    
    LL a = sum/(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            LL t = a+c*i+d*j;
            if (mp.find(t) == mp.end()) {
                cout << "NO" << endl;
                return;
            }
            else {
                if(--mp[t]==0) mp.erase(t);
            }
        }
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
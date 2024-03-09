#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const int BASE_31BIT = 0x7fffffff;

void solve() {
    int n, res = 0;
    cin>>n;
    map<int,int> mp;

    for (int i = 0; i < n; ++i){
        int x;
        cin>>x;
        if (mp.find((~x)&BASE_31BIT) != mp.end()) {
            ++res;
            --mp[BASE_31BIT&~x];
            if (mp[BASE_31BIT&~x] == 0) mp.erase(BASE_31BIT&~x);
        }
        else mp[x]++;
    }
    cout << n-res << endl;
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
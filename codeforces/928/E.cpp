#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<pair<char,int>> v;

    for (int i = 0; i < s.size(); ++i) {
        if (v.empty() || v.back().first != s[i]) v.push_back({s[i],1});
        else {
            if (++v.back().second == k) v.pop_back();
        }
    }

    string res;
    for (auto &[c,cnt] : v) {
        while (cnt--) {
            res += c;
        }
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
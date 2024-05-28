#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, res = 0;
    char c;
    string s;
    cin>>n>>c>>s;
    
    vector<int> vc, g;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) vc.push_back(i);
    }

    s += s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'g') g.push_back(i); 
    }
    for (int &i : vc) {
        int j = lower_bound(g.begin(), g.end(), i)-g.begin();
        res = max(res, g[j]-i);
    }

    cout<<res<<endl;
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
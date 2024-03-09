#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n;
    cin>>n;
    string s(n,' ');

    map<int,deque<int>,greater<int>> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        mp[x].push_back(i);
    }

    for (char c='a'; c<='z'; ++c) {
        for (auto &[cnt,dq] : mp) {
            if (dq.empty()) continue;
            s[dq.front()] = c;
            dq.pop_front();
        }
    }

    cout << s << endl;
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
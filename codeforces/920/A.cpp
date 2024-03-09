#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    unordered_map<int,vector<int>> ump;
    for (int i = 0; i< 4; ++i) {
        int a,b;
        cin>>a>>b;
        ump[a].push_back(b);
    }

    auto it = ump.begin();
    int dif = abs(it->second[0]-it->second[1]);

    cout << dif*dif << endl;
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
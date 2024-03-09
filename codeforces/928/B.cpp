#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n;
    cin>>n;
    vector<string> v(n);
    vector<int> one;

    for (int i = 0; i < n; ++i) {
        cin>>v[i];
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == '1') ++cnt;
        }
        if (cnt > 0) one.push_back(cnt);
    }

    sort(one.begin(), one.end());

    bool tri = 1;
    //triangle
    for (int i = 1; i < one.size(); ++i) {
        if (one[i]-one[i-1] != 2) {
            cout << "SQUARE" << endl;
            return;
        }
    }

    cout << "TRIANGLE" << endl;
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
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

long power(int n) {
    long ans = 1;
    while (n--) {
        ans <<= 1;
    }
    return ans;
}

void solve() {
    int n, m, res = 0;
    cin>>n>>m;
    string x, s;

    cin>>x>>s;

    while (x.size() <= 10000) {
        if (x.find(s) != x.npos) {
            cout << res << endl;
            return;
        }
        x += x;
        ++res;
    }
    cout << -1 << endl;
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
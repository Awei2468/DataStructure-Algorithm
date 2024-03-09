#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, res = 0, move = 0, fcnt = 0, scnt = 0;
    cin>>n;
    char s[n], f[n];
    for (int i = 0; i < n; ++i) cin>>s[i];
    for (int i = 0; i < n; ++i) cin>>f[i];

    for (int i = 0; i < n; ++i) {
        if (s[i]=='0' && f[i]=='1') {
            ++res;
        }
        else if (s[i]=='1' && f[i]=='0') {
            ++move;
        }
    }

    if (move >= res) cout << move << endl;
    else cout << res << endl;
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
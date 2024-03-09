#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i]=='B') {
            ++res;
            int j = i, cnt = 0;
            while (j < n && cnt < k) {
                s[j]='W';
                ++cnt;
                ++j;
            }
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
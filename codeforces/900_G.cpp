#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;

    for (int i = 0; i < m; ++i) {
        int t, l, r, x;
        cin>>t>>l>>r;
        if (t == 1) {
            cin>>x;
            x %= 26;
            for (int j = l-1; j <= r-1; ++j) {
                if (s[j]+x > 'z') s[j] = 'a'+(x-('z'-s[j]))-1;
                else s[j] += x;
            }
        }
        else {
            string _s = s.substr(l-1, r-l+1);
            //cout << _s << endl;
            int sz = _s.size(), res = 0;
            bool dp[sz][sz];
            memset(dp, false, sizeof(dp));
            for (int j = sz-1; j >= 0; --j) {//from bottom to top(because we need to calculate dp[i+1][j-1])
                for (int k = j; k < sz; ++k) {//from left to right
                    if (_s[j] == _s[k] && (k-j <= 1 || dp[j+1][k-1])) {
                        if (j+1 < sz && k-1 >= 0 && dp[j+1][k-1] || k-j == 1) {
                            cout << "NO" << endl;
                            goto NEXT;
                        }
                        ++res, dp[j][k] = true;
                    }
                }
            }

            cout << "YES" << endl;
        }
        NEXT:
        continue;
    }
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
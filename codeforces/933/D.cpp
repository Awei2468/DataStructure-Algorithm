#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, m, x;
    cin>>n>>m>>x;
    bool have[1001] = {0};

    have[x] = 1;
    for (int i = 0; i < m; ++i) {
        int r;
        char c;
        cin>>r>>c;

        vector<int> t;
        for (int i = 1; i <= n; ++i) {
            if (have[i]) {
                t.push_back(i);
                have[i] = 0;
            }
        }
        for (int &i : t) {
            int cw = i+r;
            int ccw = i-r;
            if (cw > n) cw -= n;
            if (ccw <= 0) ccw += n;
            if (c == '0') { //c
                have[cw] = 1;
            }
            else if (c == '1') { //cc
                have[ccw] = 1;
            }
            else { //both
                have[cw] = 1;
                have[ccw] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (have[i]) ++cnt;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; ++i) {
        if (have[i]) cout << i << " ";
    }
    cout << endl;
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
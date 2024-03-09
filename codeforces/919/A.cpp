#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, ma = INT_MAX, mi = INT_MIN;
    cin>>n;
    unordered_set<int> ust;

    for (int i = 0;i < n; ++i) {
        int a, x;
        cin>>a>>x;
        if (a == 1) { //>=
            mi = max(mi, x);
        }
        else if (a== 2) { //<=
            ma = min(ma, x);
        }
        else {
            ust.insert(x);
        }
    }

    if (ma >= mi) {
        int cnt = ma-mi+1;
        for (auto &i : ust) {
            if (i >= mi && i <= ma) --cnt;
        }
        cout << cnt << endl;
    }
    else cout << 0 << endl;
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
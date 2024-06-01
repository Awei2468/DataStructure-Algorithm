#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
int res = 0;

void dfs(int n, int limit, int cnt) {
    if (cnt == 3) {
        if (!n) ++res;
        return;
    }
    for (int i = 0; i <= limit; ++i) {
        dfs(n-i, limit, cnt+1);
    }
}

void solve() { //2928. Distribute Candies Among Children I
    if (limit*3 < n) return 0;
    dfs(n, limit, 0);
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
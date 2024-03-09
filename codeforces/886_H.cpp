#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long LL;

vector<LL> pos(200005);
vector<vector<pair<int,int>>> v(200005);

bool dfs(int i) {
    for (auto &[j,d] : v[i]) {
        if (pos[j] != LLONG_MIN) {
            if (pos[j] != pos[i]+d) return false;
        }
        else {
            pos[j] = pos[i]+d;
            bool ans = dfs(j);
            if (!ans) return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin>>n>>m;

    for (int i = 1; i <= n; ++i) {
        v[i].clear();
        pos[i] = LLONG_MIN;
    }
    
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin>>a>>b>>d;

        v[a].push_back({b,d});
        v[b].push_back({a,-d});
    }

    bool ans = true;
    for (int i = 1; i <= n; ++i) {
        if (pos[i] != LLONG_MIN) continue;
        pos[i] = 0;
        ans &= dfs(i);
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;

    while (t--) {
        solve();
    }

    return 0;
}

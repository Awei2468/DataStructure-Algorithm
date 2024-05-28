#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

int par[16];
int find(int u) {
    return par[u] == -1 ? u: par[u]=find(par[u]);
}
void combine(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (u < v) par[v] = u;
    else par[u] = v;
}

void solve() {
    int n, res = INT_MAX;
    cin>>n;
    string g[n], w[n];
    for (int i = 0; i < n; ++i) {
        cin>>g[i]>>w[i];
    } 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) par[j] = -1;
        unordered_set<string> ust;
        ust.insert(g[i]), ust.insert(w[i]);
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
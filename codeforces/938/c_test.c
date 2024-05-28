#include<stdio.h>

typedef unsigned long long ULL;
typedef long long LL;

int val[200001], n, mod = 1e9+7, par[200001];
char op[200001];

LL dfs(int i) {
    LL cal=val[i];
    for (int &ch : g[i]) {
        if (op[i] == '*') cal=cal*dfs(ch)%mod;
        else cal=(cal+dfs(ch))%mod;
    }
    return cal;
}

int solve(){
    scanf("%d", &n);
    for (int i = 0, id; i < n; ++i) {
        scanf("%d", &id);
        scanf("%d", &val[i+1]);
        scanf("%c", &op[i+1]);
    }
    for (int i = 0 ; i < n-1; ++i) {
        int p, child;
        scanf("%d", &p);
        scanf("%d", &child);
        g[p].push_back(child);
    }

    return dfs(1)%mod;
}

int main(){
    printf("%d", solve());
    return 0;
}
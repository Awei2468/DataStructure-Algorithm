#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void dfs(vector<int> &v, int &res, int i) {
    if (v[i] > v[i+1] || v[i] < 0) return;
    if (i == 2) {
        v[0] = v[2]-v[1];
        if (v[0] <= v[1] && v[0] >= 0) ++res;
        return;
    }
    else if (i == 1) {
        if (v[0] <= v[1] && v[0] >= 0) ++res;
        return;
    }
    v[i-2] = v[i]-v[i-1];
    dfs(v, res, i-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--) {
        int n, k, res = 0;
        cin>>n;
        cin>>k;
        vector<int> v(k);
        v[k-1] = n;
        
        for (int j = 0; j <= n/2; ++j) {
            v[k-3] = j;
            v[k-2] = n-j;
            dfs(v,res,k-2);
        }

        cout << res << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, k, x, res = INT_MIN;
    cin>>n>>k>>x;
    vector<int> v(n), presum(n), premin(n);

    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    presum[0] = v[0];
    for (int i = 1; i < n; ++i) {
        presum[i] = presum[i-1]+v[i];
    }

    for (int cnt = 0; cnt <= k; ++cnt) {
        int sum;
        if (n-1-cnt < 0) sum = 0;
        else sum = (n-1-cnt-x >= 0) ? presum[n-1-cnt]-2*(presum[n-1-cnt]-presum[n-1-cnt-x]) : -presum[n-1-cnt];
        res = max(res, sum);
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
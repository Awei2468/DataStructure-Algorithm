#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL res = 0;
    cin>>n;

    map<LL,LL> x, y, ymx, ypx; //to avoid TLE?
    for (int i = 0; i < n; ++i) {
        LL _x, _y;
        cin>>_x>>_y;
        x[_x]++;
        y[_y]++;
        ymx[_y-_x]++;
        ypx[_y+_x]++;
    }

    for (auto &[val,cnt] : x) {
        res += cnt*(cnt-1);
    }
    for (auto &[val,cnt] : y) {
        res += cnt*(cnt-1);
    }
    for (auto &[val,cnt] : ymx) {
        res += cnt*(cnt-1);
    }
    for (auto &[val,cnt] : ypx) {
        res += cnt*(cnt-1);
    }

    cout << res << endl;
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

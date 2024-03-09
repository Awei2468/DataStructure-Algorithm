#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long LL;
typedef pair<int,char> pr;

void solve() {
    LL n, f, a, b;
    cin>>n>>f>>a>>b;
    LL m[n];
    for (int i = 0; i < n; ++i) cin>>m[i];

    for (int i = 0; i < n; ++i) {
        LL x, y; //x:turn off, y:time flow
        x = f-b;
        y = f-(m[i]-(i-1 < 0 ? 0 : m[i-1]))*a;
        //cout << "x=" << x << ",y=" << y << endl;
        if (x <= 0 && y <= 0) {
            cout << "NO" << endl;
            return;
        }
        else if (x <= 0) f = y;
        else if (y <= 0) f = x;
        else f = max(x,y);
    }

    cout << "YES" << endl;
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
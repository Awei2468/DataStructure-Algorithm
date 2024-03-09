#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int l, r;
    cin>>l>>r;
    if (l == r) {
        if (l%2 == 0 && l > 2) {
            cout << 2 << " " << l-2 << endl;
            return;
        }
        for (int i = 2; i*i <= l; ++i) {
            if (l % i == 0) {
                cout << i << " " << l-i << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
    }
    for (int i = l; i <= r; ++i) {
        if ((i & 1) == 0) {
            int h = i>>1;
            if (h == 1) continue;
            cout << h << " " << h << endl;
            return;
        }
    }
    cout << -1 << endl;
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
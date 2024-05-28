#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

unordered_set<int> ust({10,11, 101,110,111,100, 1000,1001,1010,1011,1100,1101,1111,1110});

void solve() {
    int n;
    cin>>n;
    int ori = n;
    bool b=1;

    while (n) {
        int r = n%10;
        if (r != 0 && r != 1) {
            b=0;
            break;
        }
        n /= 10;
    }
    if (b) {
        cout << "YES" << endl;
        return;
    }
    
    n = ori;
    while(1) {
        bool go = 0;
        for (auto &i:ust) {
            if (n%i == 0) n/=i, go=1;
        }
        if (!go) break;
    }

    if (n==1) cout << "YES" << endl;
    else cout << "NO" << endl;
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
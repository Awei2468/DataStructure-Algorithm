#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n;
    cin>>n;
    string a,b,c;

    for (int i = 0; i < n; ++i) {
        char x;
        cin>>x;
        a += x;
    }
    for (int i = 0; i < n; ++i) {
        char x;
        cin>>x;
        b += x;
    }
    for (int i = 0; i < n; ++i) {
        char x;
        cin>>x;
        c += x;
    }

    bool chk = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != c[i] && b[i] != c[i]){
            chk = 0;
            break;
        }
    }

    if (!chk) cout << "YES" << endl;
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
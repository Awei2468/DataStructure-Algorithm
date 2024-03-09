#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n), odd, even;

    for (int i = 0; i < n; ++i) {
        v[i] = i+1;
        if (v[i] & 1) odd.push_back(v[i]);
        else even.push_back(v[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


//1 2 4 3
//1 6 3 4 5 2
//1 6 3 4 5 2 7
//1 12 3 4 5 2 7 8 9 10 11 6

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
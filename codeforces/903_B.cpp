#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    vector<int> v(3);
    for (int i = 0; i < 3; ++i) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    if (v[0] == v[1] && v[1] == v[2]) { //0
        cout << "YES" << endl;
        return;
    }
    if (v[0] == v[1] && v[2]/2 == v[0] && v[2]%2 == 0) { //1
        cout << "YES" << endl;
        return;
    }
    if (v[1]/2 == v[0] && v[1]%2 == 0 && v[2]/2 == v[0] && v[2]%2 == 0 || v[0] == v[1] && v[2]/3 == v[0] && v[2]%3 == 0 || v[1]/v[0] == 2 && v[1]%v[0] == 0 && v[2]/v[0] == 3 && v[2]%v[0] == 0) { //2
        cout << "YES" << endl;
        return;
    }
    if (v[0] == v[1] && v[2]/4 == v[0] && v[2]%4 == 0) { //3
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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
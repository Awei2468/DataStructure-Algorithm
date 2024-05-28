#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int x;
    cin>>x;
    switch(x) {
        case 1:
        cout << "yoink a\nyoink b\n*slaps a on top of b*\nyeet b\ngo touch some grass" << endl;
        break;
        case 2:
        cout << "yoink a\nbruh b is lowkey just 0\nrip this b fell off by a\nvibe check a ratios b\nsimp for 7\nbruh a is lowkey just b\nyeet a\ngo touch some grass" << endl;
        break;
        case 3:
        cout << "yoink n\nyoink a\nbruh m is lowkey just a[0]\nbruh i is lowkey just 1\nvibe check n ratios i\nsimp for 9\nyeet m\ngo touch some grass\nvibe check a[i] ratios m\nbruh m is lowkey just a[i]\n*slaps 1 on top of i*\nsimp for 5" << endl;
        break;
        case 4:
        cout << " " << endl;
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}
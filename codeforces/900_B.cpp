#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n;
    cin>>n;
    vector<int> res(n);

    res[0] = 1, res[1] = 5;
    for (int i = 2; i < n; ++i) {
        int j = res[i-1]+1, sum = res[i-1]+res[i-2];
        while (j <= 1e9) {
            if ((3*j)%sum) {
                res[i] = j;
                break;
            }
            ++j;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
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
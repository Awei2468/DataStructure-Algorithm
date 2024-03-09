#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n;
    cin>>n;
    int a[n];
    ULL even[n+5], odd[n+5];

    memset(even, 0, sizeof(even));
    memset(odd, 0, sizeof(odd));

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    // even[0] = 0;
    // odd[1] = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) odd[i+2] = odd[i]+a[i];
        else even[i+2] = even[i]+a[i];
    }

    for (int i = 2; i <= n+1; i+=2) {
        for (int j = 2; j < i; j+=2) {
            if (even[i]-even[j-2] == odd[i-1]-odd[j+1]) {
                //cout << "i=" << i << ",j=" << j << endl;
                cout << "YES" << endl;
                return;
            }
        }
    }

    for (int i = 3; i <= n+1; i+=2) {
        for (int j = 3; j < i; j+=2) {
            if (odd[i]-odd[j-2] == even[i-1]-even[j+1]) {
                //cout << "i=" << i << ",j=" << j << endl;
                cout << "YES" << endl;
                return;
            }
        }
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
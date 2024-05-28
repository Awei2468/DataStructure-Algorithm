#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int cnt[101] = {0};
    int n;
    cin>>n;
    int dig[n];
    for(int i = 0; i < n; ++i) {
        cin>>dig[i];
        cnt[dig[i]]++;
    }
    for(int i = 0; i < n; ++i) {
        if(cnt[dig[i]]==1) {
            cout<<i+1<<endl;
            break;
        }
    }
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
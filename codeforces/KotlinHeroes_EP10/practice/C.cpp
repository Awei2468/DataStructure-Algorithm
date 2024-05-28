#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int cnt[128]={0};
    int n,k,res = 0;
    cin>>n>>k;
    string s;
    cin>>s;

    for(int i = 0; i < n; ++i) {
        ++cnt[s[i]];
    }
    for(char c='A'; c<='Z'; ++c) {
        int g=abs(cnt[c]-cnt[c+32])>>1;
        res += min(cnt[c],cnt[c+32]);
        if(k >= g) k -= g, res += g;
        else {
            res += k;
            break;
        }
    }
    cout<<res<<endl;
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
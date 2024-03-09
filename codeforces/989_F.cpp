#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

ULL cal(vector<int>&a, vector<int>&h, int m, int k) {
    int n = a.size();
    ULL ans = LLONG_MAX;

    for (int i = 0; i <= max(0,n-m); ++i) {
        ULL tmp=0;
        for (int j = i+1; j < n && j <= i+m-1; ++j) {
            if (h[j-1]%h[j] || tmp>k) {
                goto NEXT;
            }
            else tmp+=a[j];
        }
        ans = min(ans,tmp+a[i]);
        NEXT:
        continue;
    }

    return ans == LLONG_MAX ? -1 : ans;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n), h(n);

    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) cin>>h[i];

    int l = 0, r = 2e5+1;
    while (l < r) {
        int m = l+(r-l)/2;
        ULL ans=cal(a,h,m,k);
        if (ans == -1) {
            r=m;
            continue;
        }
        if (k<ans) r=m;
        else l=m+1;
    }

    cout << (l ? l-1 : l) << endl;
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
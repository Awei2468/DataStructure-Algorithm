#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const int N = 200001;
long pre[N];

void solve() {
    int n;
    cin>>n;

    cout << pre[n] << endl;
}

int digSum(int x) {
    int ans = 0;
    while (x) {
        ans += x%10;
        x/=10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre[0] = 0;
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i-1]+digSum(i);
    }

    int t;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}
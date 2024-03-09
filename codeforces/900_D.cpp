#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n, k, q;
    string s;
    cin>>n>>k;
    cin>>s;
    vector<int> l(k), r(k);

    for (int i = 0; i < k; ++i) cin>>l[i];
    for (int i = 0; i < k; ++i) cin>>r[i];
    cin>>q;
    vector<int> vq(q);
    for (int i = 0; i < q; ++i) cin>>vq[i];

    for (int i = 0; i < q; ++i) {
        int t = i+1, cnt = 1, a, b, j;
        string sub1, sub2, rv;

        while (t < q && vq[t] == vq[i]) ++t, ++cnt;
        if (cnt%2 == 0) goto NEXT;

        j = lower_bound(l.begin(), l.end(), vq[i]) - l.begin();
        if (j == (int)l.size() || l[j] > vq[i]) --j;
        a = min(vq[i], l[j]+r[j]-vq[i])-1;
        b = max(vq[i], l[j]+r[j]-vq[i])-1;
        //cout << "j=" << j << ",a=" << a << ",b=" << b << endl;

        sub1 = s.substr(0, a);
        sub2 = s.substr(b+1, (int)s.size()-b-1);
        rv = s.substr(a, b-a+1);
        reverse(rv.begin(),rv.end());

        s = sub1+rv+sub2;

        NEXT:
        i = t-1;
    }

    cout << s << endl;
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
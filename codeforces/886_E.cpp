#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long LL;

LL cal(vector<int> &v, LL m) {
    LL ans = 0;
    m<<=1;
    for (int &i : v) {
        ans += (i+m)*(i+m);
    }
    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        LL n, c;
        cin>>n;
        cin>>c;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int num;
            cin>>num;
            v.push_back(num);
        }

        LL l = 1, r = 1e9;
        while (l <= r) {
            LL m = l+(r-l)/2;
            LL ans = cal(v,m);
            if (ans == c) {
                cout << m << endl;
                break;
            }
            else if (ans < c)
                l = m+1;
            else
                r = m-1;
        }
    }

    return 0;
}
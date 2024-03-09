#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, k, res = INT_MAX;
        cin>>n;
        cin>>k;
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            int num;
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            int j = i+1;
            while (j < n && v[j]-v[j-1] <= k) ++j;
            res = min(res, n-(j-i));
            i = j-1;
        }
        cout << res << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, res, score = 0;
        cin>>n;

        for (int i = 1; i <= n; ++i) {
            int len, q;
            cin>>len;
            cin>>q;
            if (len <= 10) {
                if (q > score) {
                    score = q;
                    res = i;
                }
            }
        }
        cout << res << endl;

    }
    return 0;
}
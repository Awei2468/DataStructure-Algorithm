#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() { //2401. Longest Nice Subarray
    int AND = 0, n = nums.size(), j = 0, res = 0;
        
    for (int i = 0; i < n; ++i) {
        while ((nums[i]&AND) > 0) {
            AND ^= nums[j++];
        }
        res = max(res, i-j+1);
        AND |= nums[i];
    }
    
    cout << res << endl;
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
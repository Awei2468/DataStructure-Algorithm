#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() { //pick cnt=1
    unordered_map<int,int> ump;
    vector<int> res;
    for (int &num : nums) {
        ++ump[num];
    }
    for (auto &[num,cnt] : ump) {
        if (cnt == 1) res.push_back(num);
    }

    for (int &i : res) {
        cout << i << " ";
    }
    cout << endl;
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
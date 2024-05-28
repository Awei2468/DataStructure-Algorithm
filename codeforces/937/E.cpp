#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
   int n;
   cin>>n;
   string s;
   cin>>s;

   for (int len = 1; len <= n; ++len) {
        if (n%len) continue;
        unordered_map<string,int> ump;
        bool pass = 1;
        for (int i = 0; i <= n-len; i+=len) {
            ump[s.substr(i,len)]++;
            if (ump.size() > 2) {
                pass = 0;
                break;
            }
        }
        if (pass) {
            if(ump.size()==1) {
                cout << len << endl;
                break;
            }
            else {
                int dif = 0;
                string t1 = ump.begin()->first, t2 = (++ump.begin())->first;
                //cout << t1 << " " << t2 << endl;
                for (int j = 0; j < t1.size(); ++j) {
                    if (t1[j] != t2[j]) dif += min(ump.begin()->second, (++ump.begin())->second);
                }
                if (dif <= 1) {
                    cout << len << endl;
                    break;
                } 
            }
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
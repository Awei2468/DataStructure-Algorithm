#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    string s, t;
    cin>>s;
    vector<string> v;
    int ma=0, start=-1, end=-1, n = s.size(), res = 0;
    
    for (int i = 0; i < n-1; ++i) {
        if (s.substr(i,2)=="01") {
            int j = i, _s, _e;
            while(j>=0 && s[j]=='0') --j;
            _s=j+1;
            j = i+1;
            while(j<n && s[j]=='1') ++j;
            _e=j-1;
            if (_e-_s+1>ma) {
                ma=_e-_s+1;
                start=_s, end=_e;
            }
        }
    }

    if(start!=-1 && end!=-1) {
        s.erase(start,end-start+1);
        ++res;
    }
    for(int i = 0; i < s.size(); ++i) {
        if (t.empty()) t+=s[i];
        else {
            if(t.back()==s[i]) t+=s[i];
            else {
                v.push_back(t);
                t=s[i];
            }
        }
    }
    res+=v.size();

    cout<< res+(t.empty()?0:1) << endl; 
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
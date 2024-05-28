#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
   string s;
   cin>>s;

   bool same=1;
   for (int i = 1; i < s.size(); ++i) {
       if(s[i]!= s[i-1]) {
            same = 0;
            break;
       } 
   } 
   if(same) cout<<"NO"<<endl;
   else{
        cout<<"YES"<<endl;
        for(int i = 0; i < s.size()-1; ++i) {
            if (s[i] != s[i+1]) {
                swap(s[i],s[i+1]);
                break;
            }
        }
        cout<<s<<endl;
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
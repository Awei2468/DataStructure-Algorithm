#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
   string s;
   cin>>s;
   int h = stoi(s.substr(0,2)), m = stoi(s.substr(3,2));

   if (h > 12) {
        if (h-12 < 10) cout << "0" << h-12 << ":" << s.substr(3,2) << " PM" << endl;
        else cout << h-12 << ":" << s.substr(3,2) << " PM" << endl;
   }
   else if (h == 12) {
        cout << h << ":" << s.substr(3,2) << " PM" << endl;
   }
   else {
        if (!h) cout << h+12 << ":" << s.substr(3,2) << " AM" << endl;
        else {
            if (h < 10) cout << "0" << h << ":" << s.substr(3,2) << " AM" << endl;
            else cout << h << ":" << s.substr(3,2) << " AM" << endl;
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
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
   int n;
   cin>>n;
   n<<=1;

   for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i/2)&1) { //odd row
                if ((j/2)&1) { //odd col
                    cout << "#";
                }
                else {
                    cout << ".";
                }
            }
            else { //even row
                if ((j/2)&1) { //odd col
                    cout << ".";
                }
                else {
                    cout << "#";
                }
            }
        }
        cout << endl;
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
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve() {
    for (int i = 7; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
	        printf("%c ", 'A'+j);
        }
        printf("\n");
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
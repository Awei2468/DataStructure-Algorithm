#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        string s;
        for (int i = 0 ; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                char c;
                cin>>c;
                if (c!='.') {
                    s += c;
                }
            }
        }
        cout << s << endl;
    }

    return 0;
}
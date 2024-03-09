#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef pair<int,char> pr;

void solve() {
    int n;
    cin>>n;
    string s, res, tag;
    for (int i = 0; i < n; ++i) {
        char c;
        cin>>c;
        s += c;
        if (c == 'a' || c == 'e') tag += 'V';
        else tag += 'C';
    }

    int i;
    for (i = 0; i < n; ++i) {
        if (tag.substr(i,2) == "CV" && i+3 < n && tag[i+3] == 'V') res += s.substr(i,2)+'.', ++i;
        else if (tag.substr(i,2) == "CV" && i+3 < n && tag[i+3] == 'C') res += s.substr(i,3)+'.', i+=2;
        else break;
    }
    if (i < n) res += s.substr(i, n-i);

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
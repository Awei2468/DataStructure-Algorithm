#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool b1 = 0, b2 = 0;

    if(a>b) {
        int t = a;
        a = b;
        b = t;
    }
    if(c>d) {
        int t = c;
        c = d;
        d = t;
    }
    if(b-a==1||(a==1&&b==12)||d-c==1||(c==1&&d==12)) {
        cout<<"NO"<<endl;
        return;
    }

    for(int i = a; i <= b; ++i) {
        if (c == i) {
            b1 = 1;
            break;
        }
    }
    for (int i = b; i != a+1; ++i) {
        if (i == 13) i = 1;
        if (d == i) {
            b2 = 1;
            break;
        }
    }

    if(b1 && b2) {
        cout <<"YES"<<endl;
        return;
    }
    b1 = 0, b2 = 0;

    for(int i = a; i <= b; ++i) {
        if (d == i) {
            b1 = 1;
            break;
        }
    }
    for (int i = b; i != a+1; ++i) {
        if (i == 13) i = 1;
        if (c == i) {
            b2 = 1;
            break;
        }
    }
    
    if(b1 && b2) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
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
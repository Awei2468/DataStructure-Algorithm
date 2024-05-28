#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    string a,b;
    cin>>a>>b;
    
    int cnta=0, cntb=0;
    //SML
    int na=a.size(), nb=b.size();
    if(a[na-1]=='S'&&b[nb-1]=='M') cout<<"<"<<endl;
    else if(a[na-1]=='M'&&b[nb-1]=='S') cout<<">"<<endl;
    else if(a[na-1]=='M'&&b[nb-1]=='L') cout<<"<"<<endl;
    else if(a[na-1]=='L'&&b[nb-1]=='M') cout<<">"<<endl;
    else if(a[na-1]=='S'&&b[nb-1]=='L') cout<<"<"<<endl;
    else if(a[na-1]=='L'&&b[nb-1]=='S') cout<<">"<<endl;
    else {
        cnta=na-1, cntb=nb-1;
        if(a[na-1]=='S'&&b[nb-1]=='S') {
            if(cnta>cntb) cout<<"<"<<endl;
            else if(cnta<cntb) cout<<">"<<endl;
            else cout<<"="<<endl;
        }
        else {
            if(cnta>cntb) cout<<">"<<endl;
            else if(cnta<cntb) cout<<"<"<<endl;
            else cout<<"="<<endl;
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
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    while(n--) {
        int a, b, c;
        cin>>a;
        cin>>b;
        cin>>c;

        if (a+b>= 10 || b+c >= 10 || a+c >= 10)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<endl;
    }

    return 0;
}
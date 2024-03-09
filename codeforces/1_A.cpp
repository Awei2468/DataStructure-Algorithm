#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int n, m, a, _n, _m;
    cin>>n;
    cin>>m;
    cin>>a;

    _n = (n%a == 0) ? n/a : n/a+1;
    _m = (m%a == 0) ? m/a : m/a+1;
    cout<<(long long)_n*_m;

    return 0;
}
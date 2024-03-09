#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    int total;
    cin>>total;

    while (total--) {
        bool dir = false;
        int n, t; //how many number
        cin>>n;
        vector<int> v;
        string res;
        
        while (n--) {
            cin>>t;
            if (!dir) {
                if (v.empty() || t >= v.back()) {
                    v.push_back(t);
                    res += '1';
                }
                else {
                    if (t<=v[0]) {
                        dir = true;
                        v.push_back(t);
                        res += '1';
                    }
                    else
                        res += '0';
                }
            }
            else {
                if (t >= v.back() && t <= v[0]) {
                    v.push_back(t);
                    res += '1';
                }
                else
                    res += '0';
            }
            
        }
        cout<<res<<endl;
    }

    return 0;
}
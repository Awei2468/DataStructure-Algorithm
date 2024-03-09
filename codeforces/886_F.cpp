#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;

    while (t--) {
        int n, res = 0;
        cin>>n;
        vector<int> step(n+1,0); //(step,cnt)
        vector<int> trap(n+1,0); //(pos,cnt)

        for (int i = 0; i < n; ++i) {
            int s;
            cin>>s;
            if (s <= n) step[s]++;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j+=i) {
                trap[j] += step[i];
            }
        }
        
        cout << *max_element(trap.begin(), trap.end()) << endl;
    }

    return 0;
}

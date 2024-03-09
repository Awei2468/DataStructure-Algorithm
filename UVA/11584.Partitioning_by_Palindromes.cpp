#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    int input;
    cout << "How many test case:";
    cin >> input;
    cin.get();

    string buf[input];
    int ans[input];
    for (int i = 0; i < input; ++i) {
        getline(cin, buf[i]);
    }

    for (int i = 0; i < input; ++i) {
        int sz = buf[i].size();
        bool dp[sz][sz];
        memset(dp, false, sizeof(dp));
        for (int ii = sz-1; ii >= 0; --ii) {
            for (int jj = ii; jj < sz; ++jj) {
                if (buf[i][ii] == buf[i][jj] && (jj-ii <= 1 || dp[ii+1][jj-1]))
                    dp[ii][jj] = true;
            }
        }

        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < sz; ++k) {
                if (dp[j][k]) cout << "1" << " ";
                else cout << "0" << " ";
            }
            cout << "\n";
        }

        int grp = 0;
        for (int j = 0; j < sz; ) {
            int k = sz-1;
            while (!dp[j][k]) --k;
            ++grp;
            cout << "j=" << j << ",grp=" << grp << ",k=" << k << "\n";
            j = k+1;
        }
        ans[i] = grp;
    }


    for (int i = 0; i < input; ++i)
        cout << ans[i] << "\n";

    system("pause");
    return 0;
}
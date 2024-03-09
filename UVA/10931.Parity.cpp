#include<bits/stdc++.h>
#include<iostream>

using namespace std;
pair<string,int> toBinary(int n);

int main() {
    int input;
    while (1) {
        cin >> input;
        if (!input) break;
        auto [s,cnt] = toBinary(input);
        cout << "The parity of " << s << " is " << cnt << "(mod2)." << "\n";
    }

    system("pause");
    return 0;
}

pair<string,int> toBinary(int n) {
    string ans;
    int cnt = 0;
    while (n) {
        if (n&1) {
            ans += '1';
            ++cnt;
        }
        else ans += '0';
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return {ans,cnt};
}

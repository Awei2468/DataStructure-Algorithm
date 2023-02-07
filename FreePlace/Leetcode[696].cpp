#include<iostream>
#include<string>

using namespace std;

int countBinarySubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < s.size()-1; ++i) {
        int acc = 1;
        if (s[i] == s[i+1])
            ++acc;
        else {
            int k = i+1;
            int right = i+2;
            while (acc-- > 1) {
                if (s[k] != s[right++])
                    break;
            }
        }
    }
    return ans;
}

int main() {

    string str = "00110011";
    cout << countBinarySubstrings(str) << endl;

    system("pause");
    return 0;
}

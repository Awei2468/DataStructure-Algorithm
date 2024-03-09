#include<bits/stdc++.h>
#include<iostream>

using namespace std;
bool prime[2002] = {false};
void CheckPrime();
string PrimeFreq(string);

int main() {
    CheckPrime();
    int input, input2, i = 0;

    cout << "Input test case number:";
    cin >> input;

    string testCase[input];
    input2 = input;
    while (input2--) {
        cin >> testCase[i++];
    }

    for (int i = 0; i < input; ++i) {
        cout << "Case " << i+1 << ": " << PrimeFreq(testCase[i]) << "\n";
    }

    system("pause");
    return 0;
}

void CheckPrime() {
    for (int i = 2; i < 2002; ++i) {
        bool chk = true;
        for (int j = 2; j*j <= i; ++j) {
            if (i % j == 0) {
                chk = false;
                break;
            }
        }
        if (chk) prime[i] = true;
    }
}

string PrimeFreq(string s) {
    string res = "";
    int alpha[128] = {0};
    for (char &c : s) {
        ++alpha[c];
    }
    for (char c = '0'; c <= '9'; ++c) {
        if (prime[alpha[c]]) res += c;
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (prime[alpha[c]]) res += c;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (prime[alpha[c]]) res += c;
    }
    return res;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int si = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (s[si] == t[i])
                ++si;
            if (si == s.size())
                break;
        }
        if (si == s.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
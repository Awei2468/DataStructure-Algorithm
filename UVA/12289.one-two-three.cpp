#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    while (n > 0) {
        cin >> s;
        if (s.size() == 5)
            cout << "3" << endl;
        else {
            if ((s[0] == 'o' && s[1] == 'n') || (s[1] == 'n' && s[2] == 'e') || (s[0] == 'o' && s[2] == 'e'))
                cout << "1" << endl;
            else
                cout << "2" << endl;
        }
        --n;
    }
    return 0;
}
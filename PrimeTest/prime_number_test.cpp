#include<iostream>
using namespace std;

bool check(int n);

int main() {

    int n;
    while (1) {
        cin >> n;
        for (int i = n; i >= 2; --i) {
            if (check(i)) {
                cout << "Close prime number to " << n << " is " << i << endl;
                break;
            }
        }
    }
    
    return 0;
}

bool check(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if ((n % i) == 0) return false;
    }
    return true;
}
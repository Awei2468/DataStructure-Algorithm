#include<iostream>
#include<memory.h>
#include<climits>

using namespace std;

#define row 3
#define col 4

int dp[row][col];

void ShowArray(int v[row][col]) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {

    size_t x = 2;
    cout << "sizeof size_t:" << sizeof(size_t) << endl;

    for (int i = 0; i < row; ++i) 
        memset(dp[i], 5, sizeof(dp[0][0]) * col);
    ShowArray(dp);

    memset(dp, -1, sizeof(dp));
    ShowArray(dp);

    system("pause");
    return 0;
}
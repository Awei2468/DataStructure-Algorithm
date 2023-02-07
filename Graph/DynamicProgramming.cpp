#include<iostream>
#include<iomanip>
#include<memory.h>
#include<vector>

using namespace std;

int buffer[100] = {0};
int stairs[100] = {0};
int Hanoi[100] = {0};

void PrintResult(int *Array, int length);

int Fibonacci(int n);

int ClimbStairs(int n);
int ClimbStairs_ButtomUp(int n);
int ClimbStairs_ButtomUp_3Space(int n);

int HanoiTower(int n);
int HanoiTower_ButtomUp(int n);
int HanoiTower_ButtomUp_2Space(int n);

vector<unsigned int> getRow(unsigned int rowIndex) {
    vector<unsigned int> res;
    res.resize(rowIndex+1);
    res[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        res[i] = res[i-1] * (rowIndex-i+1) / i;
    }
    return res;
}

int main(){

    cout << "Dynamic Programming." << endl;
    int n;

    cout<< Fibonacci(5) << endl;
    PrintResult(buffer, 5);
    memset(buffer, 0, 100);  //set back to zero

    cout << "-----------------------------------------------------------------------------" << endl;

    cout << ClimbStairs(8) << endl;
    PrintResult(stairs, 9);
    memset(stairs, 0 ,100);  //set back to zero

    cout << ClimbStairs_ButtomUp(8) << endl;
    PrintResult(stairs, 9);
    memset(stairs, 0, 100);

    cout << ClimbStairs_ButtomUp_3Space(8) << endl;
    PrintResult(stairs, 9);
    memset(stairs, 0, 100);

    cout << "-----------------------------------------------------------------------------" << endl;

    n = 9;
    cout << "Hanoi Tower, n = " << n << ", result = " << HanoiTower(n) << endl;
    PrintResult(Hanoi, n+1);
    memset(Hanoi, 0 , 100);

    cout << "Hanoi Tower, n = " << n << ", result = " << HanoiTower_ButtomUp(n) << endl;
    PrintResult(Hanoi, n);
    memset(Hanoi, 0 ,100);

    cout << "Hanoi Tower, n = " << n << ", result = " << HanoiTower_ButtomUp_2Space(n-1) << endl;
    PrintResult(Hanoi, n);
    memset(Hanoi, 0 ,100);

    cout << "-----------------------------------------------------------------------------" << endl;

    vector<unsigned int> V = getRow(1);

    for (int i = 0; i < V.size(); ++i)
        cout << setw(3) << V[i];

    system("pause");
    return 0;
}

void PrintResult(int *Array, int length){

    for (int i = 0; i < length; ++i) {
        cout << setw(4) << Array[i];
    }
    cout << endl;

}

int Fibonacci(int n){

    if (n == 1 || n == 2)
        return (buffer[n-1] = 1);

    if (buffer[n-1])
        return buffer[n-1];

    buffer[n-1] = Fibonacci(n-1) + Fibonacci(n-2);
    return buffer[n-1];

}

int ClimbStairs(int n){

    if (n == 0 || n == 1)
        return (stairs[n] = 1);

    if (stairs[n])
        return stairs[n];

    return stairs[n] = ClimbStairs(n-1) + ClimbStairs(n-2);  //by recursive

}

int ClimbStairs_ButtomUp(int n){

    stairs[0] = 1;
    stairs[1] = 1;

    for (int i = 2; i <= n; ++i) {  //by for loop
        stairs[i] = stairs[i-1] + stairs[i-2];
    }
    return stairs[n];

}

int ClimbStairs_ButtomUp_3Space(int n){

    stairs[0] = 1;
    stairs[1] = 1;

    for (int i = 2; i <= n; ++i) {
        stairs[2] = stairs[0] + stairs[1];  //reduce space
        stairs[0] = stairs[1];
        stairs[1] = stairs[2];
    }
    return stairs[2];

}

int HanoiTower(int n){

    if (n == 1)
        return (Hanoi[n] = 1);

    if (Hanoi[n])
        return Hanoi[n];

    return Hanoi[n] = 2*HanoiTower(n-1) + 1;

}

int HanoiTower_ButtomUp(int n){

    Hanoi[0] = 1;

    for (int i = 1; i <= n; ++i) {
        Hanoi[i] = 2*Hanoi[i-1] + 1;
    }
    return Hanoi[n-1];

}

int HanoiTower_ButtomUp_2Space(int n){

    Hanoi[0] = 1;

    for (int i = 1; i <= n; ++i) {
        Hanoi[1] = 2*Hanoi[0] + 1;
        Hanoi[0] = Hanoi[1];
    }
    return Hanoi[1];

}


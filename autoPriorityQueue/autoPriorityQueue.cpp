#include<iostream>
#include<iomanip>
#include<queue>

using namespace std;

int main(){

    cout << "Use C++ priority queue container." << endl;

    priority_queue<int> Big_Small;  //default
    priority_queue<int, vector<int>, greater<int>> Small_Big;

    int Array[] = {87, 1, 53, 100, 22, 69, 9, 43, 19, 99};

    for (int i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i) {  //insert element
        Big_Small.push(Array[i]);
        Small_Big.push(Array[i]);
    }

    cout << "priority queue size: " << Big_Small.size() << endl;

    Big_Small.emplace(456);  //insert new element
    Small_Big.emplace(456);

    cout << "priority queue size: " << Big_Small.size() << endl;

    cout << "From big to small: ";
    while (!Big_Small.empty()) {             //top() and pop() to show
        cout << setw(4) << Big_Small.top();
        Big_Small.pop();
    }
    cout << endl;

    cout << "From small to big: ";
    while (!Small_Big.empty()) {
        cout << setw(4) << Small_Big.top();
        Small_Big.pop();
    }
    cout << endl;

    cout << "priority queue size: " << Big_Small.size() << endl;

    system("pause");
    return 0;
}

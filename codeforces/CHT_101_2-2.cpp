#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Employee {
public:
    virtual void calculateSalary(void) = 0;
};

class Manager:public Employee {
private:
    int base;
public:
    Manager() {
        base = 24000;
    }
    virtual void calculateSalary(void);
};

class Staff:public Employee {
private:
    int base;
public:
    Staff() {
        base = 24000;
    }
    virtual void calculateSalary(void);
};

void Manager::calculateSalary(void) {
    cout << base+30000 << endl;
}

void Staff::calculateSalary(void) {
    cout << base+24000 << endl;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    
    Manager M1;
    Staff S1;

    M1.calculateSalary();
    S1.calculateSalary();

    int x = 5, y = 3;
    cout << "before:" << "x=" << x << ", y=" << y << endl;
    swap(&x,&y);
    cout << "after:" << "x=" << x << ", y=" << y << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

union _unionA {
    int a[5];
    char b;
    double c;
};

struct B {
    int n;
    _unionA a;
    char c[10];
};

#pragma pack(8)
struct example1 {
    short a;
    long b;
};

struct example2 {
    char c;
    example1 ex1;
    short e;
};


struct example3 {
    char a;
    short b;
    int c;
    ll d;
};
#pragma pack(0)

#define COUNT_OFFSET(id, element) ((unsigned long) & ((struct id*)0)->element)

int main() {

    cout << "size of _unionA:" << sizeof(_unionA) << "\n";
    cout << "size of B:" << sizeof(B) << "\n";

    example2 ex2;
    long t1;
    ll t2;
    cout << "size of long type:" << sizeof(t1) << endl;
    cout << "size of long long type:" << sizeof(t2) << endl;
    cout << "size of example1:" << sizeof(example1) << endl;
    cout << "size of example2:" << sizeof(example2) << endl;
    cout << (unsigned int)(&ex2.ex1) - (unsigned int)(&ex2) << endl;

    cout << COUNT_OFFSET(example2, e) << endl;

    cout << "=========================================\n";

    example3 ex3[2];
    cout << "size of example3:" << sizeof(example3) << "\n";
    cout << "example3(size a):" << COUNT_OFFSET(example3, b) << "\n";
    cout << "example3(size b):" << COUNT_OFFSET(example3, c) - COUNT_OFFSET(example3, b) << "\n";
    cout << "example3(size c):" << COUNT_OFFSET(example3, d) - COUNT_OFFSET(example3, c) << "\n";
    cout << "(size d):" << (ull)&ex3[1] - (ull)&ex3[0].d << "\n";  //best solution, 需要強制轉型避免錯誤

    cout << "example3(addr):" << &ex3[0] << "\n";
    cout << "example3(addr b):" << hex << &ex3[0].b << "\n";
    cout << "example3(addr c):" << hex << &ex3[0].c << "\n";
    cout << "example3(addr d):" << hex << &ex3[0].d << "\n";

    cout << "size of string:" << sizeof("abcdefgh") << "\n";  //9, 字串常量本身應看成陣列

    system("pause");
    return 0;
}
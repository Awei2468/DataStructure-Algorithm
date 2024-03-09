#include<bits/stdc++.h>
#include<iostream>

using namespace std;

typedef struct {
	int a[5];
} foo;

#pragma pack(4)
typedef struct {
	char a[5];
	int b;
    long long l;
} bar;
#pragma pack()

int main()
{
    cout << sizeof(size_t) << endl;
    cout << sizeof(bar) << endl;
	printf("%d\n", ((foo*)0)+5);
	printf("%d\n", ((bar*)0)+1);

    return 0;
}
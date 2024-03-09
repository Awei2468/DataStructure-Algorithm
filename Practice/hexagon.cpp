#include<bits/stdc++.h>
#include<iostream>

using namespace std;
void ShowHexagon(int x);

int main(){
    int line, height[1000];
    cout << "line number(input must small than 1000):"; cin>>line;
    for (int i = 0; i < line; ++i) {
        cout << "height[" << i << "]=";
        cin >> height[i];
    }

    for (int i = 0; i < line; ++i)
        ShowHexagon(height[i]);
    
    system("pause");
    return 0;
}

void ShowHexagon(int x) {
    int tri[x], res[2*x-3], ma = (1+(x-1)*2+1)>>1;
    memset(res, 0, sizeof(res));
    for (int i = 0, j = 1; i < x; ++i, j+=2)
        res[i] = tri[i] = j;
    for (int i = 2*x-4, j = 0; i >= x-3; --i, ++j)
        res[i] = max(res[i],tri[j]);
    for (int i = 0; i < 2*x-3; ++i) {
        int blank = ma-(res[i]+1)/2;
        while (blank--) cout << " ";
        while (res[i]--) cout << "*";
        cout << "\n";
    }
}
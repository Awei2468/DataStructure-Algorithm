#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, mi = 1000;
    cin>>n;
    //3a+5b
    for(int i = 0; i*5 <= n; ++i) {
        int t = n-5*i;
        if(t%3 == 0) {
            cout<<0<<endl;
            return;
        }
        else {
            mi = min(mi,t%3);
        }
    }
    cout<<mi<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
    
    return 0;
}

/*
fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val list = mutableListOf<Int>()
    repeat(n){
        val howManyNumbers = readLine()!!.toInt()
        val numbers = readLine()!!.split(' ').map { it.toInt() }
        val group = numbers.groupBy { it }.map { Pair(it.key, it.value.count()) }.find { it.second == 1 }
 
        list.add(numbers.indexOf(group!!.first) + 1)
    }
    list.forEach {
        println(it)
    }
}
*/
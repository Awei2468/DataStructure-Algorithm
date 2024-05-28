#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

//question: receive server latency, and calculate k size average, ignore top x values
/*
一個server定期會收到latency，計算k個平均latency，忽略最大x個值
ex:[20,30,40,80,100] k=5 x=2 avg=(20+30+40)/5=18
*/
class Server{ 
    int time=0, k, mx;
    long pre=0;
    map<int,int> hash; //(time,latency)
    priority_queue<int, vector<int>, greater<int>> pq; //size:mx
public:
Server(int k, int mx) {
    this->k=k;
    this->mx=mx;
}
void addLatency(int x) {
    if(dq.size()<k) {
        pre+=x;
        hash[time] = x;
    }
    else {
        pre-=hash.begin()->second;
        hash.erase(hash.begin());
    }
    ++time;
}
int calculateAvg(void) {
    pre=0;
    
    for (auto &[t,lat]:hash) {
        pre+=lat;
        if(pq.size()<mx) {
            pq.emplace(lat);
        }
        else {
            pq.pop();
            pq.emplace(lat);
        }
    }
    while(!pq.empty()) {
        pre-=pq.top();
        pq.pop();
    }

    return pre/k;
}
};

bool oneWay(string s1, string s2) {
    if (abs((int)s1.size()-(int)s2.size())>1) return false;
    unordered_map<char,int> hash;
    for (char &c : s1) {
        ++hash[c];
    }

    for (char &c : s2) {
        if (--hash[c] == 0) {
            hash.erase(c);
        }
    }

    if(hash.size()==1) return true; //remove,insert
    else {
        if (hash.size()>2) return false;
        bool pos1 = 0, neg1 = 0; //replace
        for (auto &[c,val] : hash) {
            if (val == 1) pos1 = true;
            if (val == -1) neg1 = true;
        }
        return pos1 && neg1;
    }
}

void replaceSpace(string &s, int len) {
    int add = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') ++add;
    }

    for (int i = len-1, j = len+add*2-1; i >= 0; --i) {
        if(s[i] != ' '){
            s[j--] = s[i];
        }
        else{
            s[j] = '0', s[j-1] = '2', s[j-2] = '%';
            j -= 3;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //test 1
    string s="Mr John Smith    ";
    replaceSpace(s, 13);
    cout<<s<<endl;

    //test 2
    cout << oneWay("pale","ple") << endl;
    cout << oneWay("pales","pale") << endl;
    cout << oneWay("pale","bale") << endl;
    cout << oneWay("pale","bae") << endl;
    cout << oneWay("pale","pales") << endl;
    
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, k, q;
    cin>>n>>k>>q;
    LL pt[k], t[k], pre=0, query[q];
    map<LL,pair<LL,int>> sum; //(time accumulate, (pos,index))
    sum[0] = {0,-1};

    for(int i = 0; i < k; ++i) {
        cin>>pt[i];
    }
    for(int i = 0; i < k; ++i) {
        cin>>t[i];
    }
    for(int i = 0; i < q; ++i) {
        cin>>query[i];
    }

    for(int i=0; i<k; ++i) {
        if(!i) sum[pt[i]]={t[i],i}, pre=t[i];
        else sum[pt[i]]={pre+(t[i]-t[i-1]),i}, pre+=t[i]-t[i-1];
    }
    for(int i=0; i < q; ++i) {
        if(!query[i]) {
            cout << 0 << " ";
            continue;
        }
        auto it=sum.lower_bound(query[i]);
        LL next_pos=pt[it->second.second], next_t=t[it->second.second];

        --it;
        LL pre_pos=(it->second.second==-1 ? 0:pt[it->second.second]), pre_t=(it->second.second==-1 ? 0:t[it->second.second]), pre_ans=it->second.first;
        cout << (pre_ans+(query[i]-pre_pos)*(next_t-pre_t)/(next_pos-pre_pos)) << " ";
    }
    cout<<endl;
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
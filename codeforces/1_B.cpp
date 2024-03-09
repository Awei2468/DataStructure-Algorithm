#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    int n;

    cin>>n;
    for (int i = 0; i < n; ++i) {
        string t, res;
        cin>>t;
        int r=0, c=0, jc=-1;
        string sr, sc;

        int p1 = t.find("R");
        int p2 = t.find("C");
        bool num = (p1==t.npos || p2==t.npos) ? false : true;

        if (num) {
            for (int i = p1+1; i < p2; ++i) {
                if (!isNumber(t[i])) {
                    num = false;
                    break;
                }
            }
        }

        if (p1!=t.npos && p2!=t.npos && p2-p1 > 1 && num) { //turn to BC23
            for (int j = 1; j < (int)t.size(); ++j) {
                if (t[j]=='C') {
                    jc=j;
                    continue;
                }
                if (jc==-1) sr += t[j];
                else sc += t[j];
            }
            if (sc != "") c = stoi(sc);

            while (c) {
                if (c%26==0) {
                    res += 'Z';
                    c-=26;
                }
                else res += c%26-1+'A';
                c /= 26;
            }
            reverse(res.begin(), res.end());
            while(sr[0]=='0') sr.erase(0,1); //erase 0
            res += sr;
        }
        else { //turn to R23C55
            for (int j = 0; j < (int)t.size(); ++j) {
                if (isUpper(t[j])) c = c*26+(t[j]+1-'A');
                else sr += t[j];
            }
            while(sr[0]=='0') sr.erase(0,1); //erase 0
            res += 'R';
            res += sr;
            res += 'C';
            res += to_string(c);
        }

        cout<<res<<endl;
    }

    

    return 0;
}
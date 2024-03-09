#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>

using namespace std;

string Haab_month[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
                         "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string Tzolkin_name[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
                           "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
const int Haab_year = 365;  

int main() {
    unordered_map<string,int> haab;
    unordered_map<int,string> tzolkin;
    for (int i = 0; i < 19; ++i)
        haab[Haab_month[i]] = i;

    for (int i = 1; i <= 260; ++i) {
        string t;
        t += to_string(i%13 ? i%13 : 13);
        t += " ";
        t += Tzolkin_name[(i-1)%20];
        tzolkin[i] = t;
    }

    int input;
    cout << "How many test case:";
    cin >> input;
    cin.get();

    string record[input];
    for (int i = 0; i < input; ++i) {
        getline(cin, record[i]);
        //cin.get();
    }

    cout << input << "\n";
    for (int i = 0; i < input; ++i) {
        int day=0, year=0;
        string month="";
        bool dot = false;
        for (int j = 0, blank = 0; j < record[i].size(); ++j) {
            if (record[i][j] == '.') dot = true;
            if (record[i][j] == ' ') {
                blank++;
                continue;
            }
            if (!dot) day = day*10 + record[i][j]-'0';
            if (blank == 1) month += record[i][j];
            if (blank == 2) year = year*10 + record[i][j]-'0';
        }
        //cout << "day=" << day << ",month=" << month << ",year=" << year << "\n"; //debug
        int total = 365*year + 20*haab[month] + (day+1);
        int new_year = total / 260;
        cout << tzolkin[total-new_year*260] << " " << new_year << "\n";
    }

    system("pause");
    return 0;
}
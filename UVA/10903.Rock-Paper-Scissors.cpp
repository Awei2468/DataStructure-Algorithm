#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int people, round, idx = 0;
    cout << "How many people and rounds:";
    cin >> people >> round;
    cin.get(); //eliminate /r

    //cout << "people=" << people << ",round=" << round << "\n";

    int record[people][2]; //0:win 1:lose
    string contest[round];
    memset(record, 0, sizeof(record));


    while (1) {
        cout << "Round " << idx+1 << ":";
        getline(cin, contest[idx++]);
        if (idx == round) break;
    }

    for (int i = 0; i < round; ++i) {
        string p1, p1_move, p2, p2_move;
        int blank = 0;
        for (int j = 0; j < contest[i].size(); ++j) {
            if (contest[i][j] >= '0' && contest[i][j] <= '9') {
                blank < 2 ? p1 += contest[i][j] : p2 += contest[i][j];
            }
            else if (contest[i][j] >= 'a' && contest[i][j] <= 'z') {
                blank < 2 ? p1_move += contest[i][j] : p2_move += contest[i][j];
            }
            else blank++;
        }

        if (p1_move == "rock" && p2_move == "scissors") record[stoi(p1)-1][0]++, record[stoi(p2)-1][1]++;
        else if (p1_move == "scissors" && p2_move == "rock") record[stoi(p1)-1][1]++, record[stoi(p2)-1][0]++;
        else if (p1_move == "paper" && p2_move == "rock") record[stoi(p1)-1][0]++, record[stoi(p2)-1][1]++;
        else if (p1_move == "rock" && p2_move == "paper") record[stoi(p1)-1][1]++, record[stoi(p2)-1][0]++;
        else if (p1_move == "scissors" && p2_move == "paper") record[stoi(p1)-1][0]++, record[stoi(p2)-1][1]++;
        else if (p1_move == "paper" && p2_move == "scissors") record[stoi(p1)-1][1]++, record[stoi(p2)-1][0]++;
    }

    for (int i = 0; i < people; ++i) {
        cout << fixed << setprecision(3) << (double)record[i][0] / (record[i][0]+record[i][1]) << "\n";
    }

    system("pause");
    return 0;
}


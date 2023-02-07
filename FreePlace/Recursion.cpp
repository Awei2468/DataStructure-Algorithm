#include<bits/stdc++.h>

using namespace std;

void ShowResult(vector<vector<int>> v);
void Combination(int n, int k);
void Backtracking_combine(vector<int> &t, int &count, int pos, int n, int k);
void Permutation(int n, int k);
void Backtracking_permutate(vector<int> &t, int &count, int n, int k);

vector<vector<int>> ans_combination;
vector<vector<int>> ans_permutation;

int main() {

    Combination(4, 2);
    ShowResult(ans_combination);

    Permutation(4, 2);
    ShowResult(ans_permutation);

    system("pause");
    return 0;
}

void ShowResult(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << "(";
        for (int j = 0; j < v[0].size(); ++j) {
            if (j != v[0].size()-1)
                cout << v[i][j] << ",";
            else
                cout << v[i][j];
        }
        cout << ")\n";
    }
    cout << "\n";
}

void Combination(int n, int k) {
    vector<int> t(k, 0);
    int count = 0;
    Backtracking_combine(t, count, 1, n, k);
}

void Backtracking_combine(vector<int> &t, int &count, int pos, int n, int k) {
    if (count == k) {
        ans_combination.push_back(t);
        return;
    }
    for (int i = pos; i <= n; ++i) {
        t[count++] = i;
        Backtracking_combine(t, count, i + 1, n, k);
        count--;
    }
}

void Permutation(int n, int k) {
    vector<int> t(k, 0);
    int count = 0;
    Backtracking_permutate(t, count, n, k);
}

void Backtracking_permutate(vector<int> &t, int &count, int n, int k) {
    if (count == k) {
        if (t[0] ^ t[1])
            ans_permutation.push_back(t);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        t[count++] = i;
        Backtracking_permutate(t, count, n, k);
        --count;
    }
}
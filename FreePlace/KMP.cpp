#include<iostream>
#include<string>

using namespace std;

void getNext(string, int*);
int KMP(string, string, int*);

int main() {

    string target = "abcabcabcabe";
    string pattern1 = "abcabe";
    string pattern2 = "abcaf";
    int *Next;

    Next = new int[20];
    getNext(pattern1, Next);
    cout << KMP(target, pattern1, Next) << endl;

    getNext(pattern2, Next);
    cout << KMP(target, pattern2, Next) << endl;

    delete[] Next;
    Next = nullptr;

    system("pause");
    return 0;
}

void getNext(string p, int* next) {
    next[0] = -1;
    int i = 0, j = -1;

    while (i < p.size()) {
        if (j == -1 || p[i] == p[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int KMP(string t, string p, int *next) {
    int i = 0, j = 0;

    while (i < t.size() && j < p.size()) {
        if (j == -1 || t[i] == p[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    if (j == p.size())
        return i-j;
    else
        return -1; 
}
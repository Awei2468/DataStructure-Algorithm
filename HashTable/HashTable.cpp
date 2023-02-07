#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

const int BOXNUMBER = 6;

struct Node{
    int number;
    char name[15];
    Node *next;
    Node():number(0),next(NULL){};
    Node(int x):number(x),next(NULL){};
};

Node NodeTable[BOXNUMBER];

void BuildHashTable(int n, char *name);
void PrintHashTable(int n);
int FindPlayer(int n);

int main(){

    srand(time(0));

    int Totalpeople = 10, test, count;
    Node *start;
    char Name[Totalpeople][15] = {"Kobe", "Adam", "Harden", "Helen", "Anthony", "Westbrook", "Irving", "Paul", "James", "Davis"};
    int tag[Totalpeople];

    for (int i = 0; i < Totalpeople; ++i) {
        tag[i] = rand() % 200 + 1;
        for (int j = 0; j < i; ++j) {
            if (tag[j] == tag[i]) {
                --i;
                break;
            }
        }
    }

    for (int i = 0; i < Totalpeople; ++i)
        cout << "tag[" << i+1 << "] = " << tag[i] << " ";
    cout << endl;

    for (int i = 0; i < Totalpeople; ++i)
        BuildHashTable(tag[i], Name[i]);

    cout << "Hash Table:" << endl;
    for (int i = 0; i < BOXNUMBER; ++i)
        PrintHashTable(i);

    while (true) {
        cout << "Input a number (1~200), -1 exit:";
        cin >> test;

        if (test == -1)
            break;
        count = FindPlayer(test);

        start = NodeTable[test%BOXNUMBER].next;

        for (int i = 1; i < count; ++i)
            start= start->next;

        if (count)
            cout << "Yes, you find " << test << ", and name is " << start->name << ", total find " << count << " times" << endl;
        else
            cout << "No, you don't find " << test << endl; 
        
    }

    /*
    for (int i = 0; i < BOXNUMBER; ++i) {
        cout << NodeTable[i].number;
        if (!NodeTable[i].next)
            cout << ",Its next is NULL" << endl;
    }
    */

    system("pause");
    return 0;
}

void BuildHashTable(int n, char *name){
    Node *newNode = new Node(n);
    int hash = n % BOXNUMBER;
    int i;

    for (i = 0; name[i] != '\0'; ++i)
        newNode->name[i] = name[i];
    newNode->name[i] = '\0';

    newNode->next = NodeTable[hash].next;
    NodeTable[hash].next = newNode;
}

void PrintHashTable(int n){
    Node *head = NodeTable[n].next;
    cout << n << ":\t";
    while (head) {
        cout << "[" << head->number << "]" << head->name;
        if (head->next) cout << " - ";
        head = head->next;
    }
    cout << endl;
}

int FindPlayer(int n){
    int hash = n % BOXNUMBER;
    int counter = 0;
    Node *head = NodeTable[hash].next;

    while (head) {
        ++counter;
        if (head->number == n)
            return counter;
        else
            head = head->next;
    }
    return 0;
}
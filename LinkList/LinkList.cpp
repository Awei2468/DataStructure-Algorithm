#include<iostream>
#include<iomanip>

using namespace std;

char NameList[10][15] = {"Adam", "Kobe", "James", "Westbrook", "Paul", "Irving", "Anthony", "Amy", "Kevin", "Howard"};

struct Node {
    int num;
    char name[15];
    Node *next;

    Node():num(0),next(NULL){};
    Node(int n):num(n),next(NULL){};
};

class ListNode {
    private:
        Node *start;
        int counter = 0;
    public:
        ListNode():start(NULL){};
        void PrintInformation(void);
        void Add_Front(int x);
        void Add_Back(int x);
        void Push_Ahead(int target, int x);
        void Push_Behind(int target, int x);
        void Delete_Node(int x);
        void Clear(void);
        void Reverse(void);
};

void ListNode::PrintInformation(void){
    cout << ++counter << " operation:" << endl;
    if (start) {
        Node *current = start;
        while (current) {
            cout << setw(5) << "[" << current->num << "]" << " " << current->name << endl;
            current = current->next;
        }
    }
    else {
        cout << "List is empty." << endl;
    }
    cout << endl;
}

void ListNode::Add_Front(int x){
    Node *newNode = new Node(x);
    int i;
    for (i = 0; NameList[x-1][i] != '\0'; ++i) {  //need deep copy!
        newNode->name[i] = NameList[x-1][i];
    }
    newNode->name[i+1] = '\0';

    if (start) {
        newNode->next = start;
        start = newNode;
    }
    else {
        start = newNode;
    }
}

void ListNode::Add_Back(int x){
    Node *newNode = new Node(x);
    int i;
    for (i = 0; NameList[x-1][i] != '\0'; ++i) {  //need deep copy!
        newNode->name[i] = NameList[x-1][i];
    }
    newNode->name[i+1] = '\0';

    if (start) {
        Node *current = start;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    else {
        start = newNode;
    }
}

void ListNode::Push_Ahead(int target, int x){
    if (!start) {
        cout << "List is empty." << endl;
        return;
    }

    Node *newNode = new Node(x);
    int i;
    for (i = 0; NameList[x-1][i] != '\0'; ++i) {
        newNode->name[i] = NameList[x-1][i];
    }
    newNode->name[i+1] = '\0';

    Node *current = start, *previous = NULL;
    while (current && current->num != target) {
        previous = current;
        current = current->next;
    }

    if (!current)
        cout << "Target is not in the list." << endl;
    else if (current == start) {
        newNode->next = start;
        start = newNode;
    }
    else {
        newNode->next = current;
        previous->next = newNode;
    }
}

void ListNode::Push_Behind(int target, int x){
    if (!start) {
        cout << "List is empty." << endl;
        return;
    } 

    Node *newNode = new Node(x);
    int i;
    for (i = 0; NameList[x-1][i] != '\0'; ++i) {
        newNode->name[i] = NameList[x-1][i];
    }
    newNode->name[i+1] = '\0';

    Node *current = start;
    while (current && current->num != target) {
        current = current->next;
    }

    if (current->next) {
        newNode->next = current->next;
        current->next = newNode;
    }
    else if (!current->next) {
        current->next = newNode;
    }
    else if (!current) {
        cout << "Target is not in the list." << endl;
    }
}

void ListNode::Delete_Node(int x){
    Node *current = start, *previous = NULL;
    while (current && current->num != x) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        cout << "Node:" << x << " is not in the list." << endl;
    }
    else if (current == start) {
        start = start->next;
        delete current;
        current = NULL;
    }
    else {
        previous->next = current->next;
        delete current;
        current = NULL;
    }
}

void ListNode::Clear(void){
    while (start) {
        Node *deleteNode = start;
        start = start->next;
        delete deleteNode;
        deleteNode = NULL;
    }
}

void ListNode::Reverse(void){
    Node *previous = NULL, *current = start, *preceding = start->next;

    if (!start || !(start->next)) {
        cout << "List is empty or only one member." << endl;
    }
    else {
        while (preceding) {
            current->next = previous;
            previous = current;
            current = preceding;
            preceding = preceding->next;
        }
        current->next = previous;
        start = current;
    }
}

int main(){

    cout << "Show Classmates by link-list." << endl;

    ListNode Class_1;

    Class_1.Add_Front(2);
    Class_1.Add_Front(5);
    Class_1.Add_Front(1);
    Class_1.PrintInformation();

    Class_1.Push_Ahead(1,4);
    Class_1.PrintInformation();

    Class_1.Add_Back(6);
    Class_1.Add_Back(9);
    Class_1.PrintInformation();

    Class_1.Push_Behind(5,10);
    Class_1.PrintInformation();

    Class_1.Push_Behind(6,8);
    Class_1.PrintInformation();

    Class_1.Reverse();
    Class_1.PrintInformation();

    Class_1.Delete_Node(7);

    Class_1.Delete_Node(4);
    Class_1.PrintInformation();

    Class_1.Delete_Node(9);
    Class_1.PrintInformation();

    Class_1.Clear();
    Class_1.PrintInformation();

    system("pause");
    return 0;
}
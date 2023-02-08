#include<iostream>
#include<iomanip>

using namespace std;

struct Node {
    int val;
    struct Node *pre, *next;

    Node(): pre(nullptr), next(nullptr){};
    Node(int num): val(num), pre(nullptr), next(nullptr){};
};

class DoubleLinkList {
private:
    struct Node *head;

public:
    DoubleLinkList(): head(nullptr){};
    DoubleLinkList(int num) {
        head = new Node(num);
    }

    void PrintResult(void);
    void PushFront(int num);
    void PushBack(int num);
    void Clear(void);
    void DeleteNode(int num);
    void Reverse(void);
    void PushAheadOneNode(int target, int num);
    void PushBehindOneNode(int target, int num);
};

void DoubleLinkList::PrintResult(void) {
    struct Node *cur = head;

    if (!cur) {
        cout << "The double link list is empty\n";
        return;
    }
    
    while (cur) {
        cout << setw(4) << cur->val;
        cur = cur->next;
    }
    cout << "\n";
}

void DoubleLinkList::PushFront(int num) {
    if (!head) {
        head = new Node(num);
        return;
    }

    struct Node *newNode = new Node(num);

    newNode->next = head;
    head->pre = newNode;
    head = newNode;
}

void DoubleLinkList::PushBack(int num) {
    if (!head) {
        head = new Node(num);
        return;
    }

    struct Node *cur = head, *newNode = new Node(num);

    while (cur->next) {
        cur = cur->next;
    }

    cur->next = newNode;
    newNode->pre = cur;
}

void DoubleLinkList::Clear(void) {
    while (head) {
        struct Node *cur = head;
        head = head->next;
        delete cur;
        cur = nullptr;
    }
}

void DoubleLinkList::DeleteNode(int num) {
    struct Node *cur = head;

    while (cur && cur->val != num) {
        cur = cur->next;
    }

    if (!cur) {
        cout << num << " didn't appear in the double link list\n";
    }
    else if (cur == head) {
        head = head->next;
        delete cur;
        cur = nullptr;
    }
    else if (!cur->next) {
        cur->pre->next = nullptr;
        delete cur;
        cur = nullptr;
    }
    else {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        delete cur;
        cur = nullptr;
    }
}

void DoubleLinkList::Reverse(void) {
    struct Node *cur = head;

    while (cur->next) {
        cur = cur->next;
    }

    while (cur) {
        cout << setw(4) << cur->val;
        cur = cur->pre;
    }

    cout << "\n";
}

void DoubleLinkList::PushAheadOneNode(int target, int num) {
    struct Node *newNode = new Node(num), *cur = head;

    while (cur && cur->val != target) {
        cur = cur->next;
    }

    if (!cur) {
        cout << target << " didn't appear in the double link list\n";
    }
    else if (cur == head) {
        newNode->next = cur;
        cur->pre = newNode;
        head = newNode;
    }
    else {
        newNode->pre = cur->pre;
        newNode->next = cur;
        cur->pre->next = newNode;
        cur->pre = newNode;
    }
}

void DoubleLinkList::PushBehindOneNode(int target, int num) {
    struct Node *cur = head, *newNode = new Node(num);

    while (cur && cur->val != target) {
        cur = cur->next;
    }

    if (!cur) {
        cout << target << " didn't appear in the double link list\n";
    }
    else if (!cur->next) {
        cur->next = newNode;
        newNode->pre = cur;
    }
    else {
        newNode->pre = cur;
        newNode->next = cur->next;
        cur->next->pre = newNode;
        cur->next = newNode;
    }
}

int main() {

    DoubleLinkList myDouble(0);

    myDouble.PushFront(8);
    myDouble.PushBack(20);
    myDouble.PrintResult(); //8 <-> 0 <-> 20

    myDouble.Reverse(); //20 <-> 0 <-> 8

    myDouble.PushAheadOneNode(20,35); 
    myDouble.PrintResult(); //8 <-> 0 <-> 35 <-> 20

    myDouble.PushAheadOneNode(8,66); 
    myDouble.PrintResult(); //66 <-> 8 <-> 0 <-> 35 <-> 20

    myDouble.PushAheadOneNode(100,200);
    myDouble.PrintResult(); //100 didn't appear in the double link list

    myDouble.PushBehindOneNode(66,72);
    myDouble.PrintResult(); //66 <-> 72 <-> 8 <-> 0 <-> 35 <-> 20

    myDouble.PushBehindOneNode(20,150);
    myDouble.PrintResult(); //66 <-> 72 <-> 8 <-> 0 <-> 35 <-> 20 <-> 150

    myDouble.PushBehindOneNode(60,80);
    myDouble.PrintResult(); //60 didn't appear in the double link list

    myDouble.DeleteNode(66);
    myDouble.PrintResult(); //72 <-> 8 <-> 0 <-> 35 <-> 20 <-> 150

    myDouble.DeleteNode(0);
    myDouble.PrintResult(); //72 <-> 8 <-> 35 <-> 20 <-> 150

    myDouble.Clear();
    myDouble.PrintResult(); //The double link list is empty

    system("pause");
    return 0;
}
#include<iostream>
#include<iomanip>

using namespace std;

struct Node {
    int val;
    struct Node *next;

    Node(int num): val(num), next(nullptr){};
    Node(): next(nullptr){};
};

class LinkList {
public:
    struct Node *head;

    LinkList(): head(nullptr){};  //default constructor, implicit
    LinkList(int num) {           //copy constructor, explicit
        head = new Node(num);
    }
    void PrintResult(void);
    void PushFront(int num);
    void PushBack(int num);
    void Clear(void);
    void DeleteNode(int num);
    struct Node* Reverse(struct Node *h);
    void PushAheadOneNode(int target, int num);
    void PushBehindOneNode(int target, int num);
};

void LinkList::PrintResult(void) {
    struct Node *cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

void LinkList::PushFront(int num) {
    if (!head) {
        head = new Node(num);
        return;
    }
    Node *newNode = new Node(num);
    newNode->next = head;
    head = newNode;
}

void LinkList::PushBack(int num) {
    if (!head) {
        head = new Node(num);
        return;
    }
    Node *newNode = new Node(num), *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = newNode;
}

void LinkList::Clear(void) {
    while (head) {
        Node *cur = head;
        head = head->next;
        delete cur;
        cur = nullptr;
    }
}

void LinkList::DeleteNode(int num) {
    Node *pre = nullptr, *cur = head;
    while (cur && cur->val != num) {
        pre = cur;
        cur = cur->next;
    }

    if (!cur) cout << "LinkList is empty or num isn't exist." << endl;
    else if (!pre) {
        head = head->next;
        delete cur;
        cur = nullptr;
    }
    else {
        pre->next = cur->next;
        delete cur;
        cur = nullptr;
    }
}

struct Node* LinkList::Reverse(struct Node *h) {
    if (!h || !h->next) return h;
    struct Node *t = Reverse(h->next);
    h->next->next = h;
    h->next = nullptr;
    return t;
}

void LinkList::PushAheadOneNode(int target, int num) {
    Node *newNode = new Node(num);
    Node *cur = head, *pre = nullptr;
    while (cur && cur->val != target) {
        pre = cur;
        cur = cur->next;
    }

    if (!cur) {  //target didn't exist
        cout << "Target didn't exist\n";
    }
    else if (!pre) {
        newNode->next = head;
        head = newNode;
    }
    else {
        pre->next = newNode;
        newNode->next = cur;
    }
}

void LinkList::PushBehindOneNode(int target, int num) {
    Node *newNode = new Node(num);
    Node *cur = head;
    while (cur && cur->val != target)
        cur = cur->next;

    if (!cur) {  //target didn't exist
        cout << "Target didn't exist\n";
    }
    else {
        Node *t = cur->next;
        cur->next = newNode;
        newNode->next = t;
    }
}

int main() {
    //LinkList myList;
    LinkList myList(1);

    myList.PushBack(5);
    myList.PushFront(-2);
    myList.PushBack(13);
    myList.PushFront(50);
    myList.PrintResult();

    myList.DeleteNode(50);
    myList.PrintResult();

    myList.DeleteNode(7);
    myList.PrintResult();

    myList.head = myList.Reverse(myList.head);
    myList.PrintResult();

    myList.PushBack(28);
    myList.PrintResult();

    myList.head = myList.Reverse(myList.head);
    myList.PrintResult();

    //20220111 new command
    myList.PushAheadOneNode(28, 35);
    myList.PrintResult();

    myList.PushAheadOneNode(1, 40);
    myList.PrintResult();

    myList.PushAheadOneNode(100, 200);
    myList.PrintResult();

    myList.PushBehindOneNode(35, 53);
    myList.PrintResult();

    myList.PushBehindOneNode(13, 66);
    myList.PrintResult();

    myList.PushBehindOneNode(1, 2);
    myList.PrintResult();

    myList.PushBehindOneNode(100,300);
    myList.PrintResult();

    myList.Clear();
    myList.PrintResult();

    system("pause");
    return 0;
}
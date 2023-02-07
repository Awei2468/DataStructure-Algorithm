#include <iostream>
#include <iomanip>
using namespace std;

struct Node {       //Single Linked Node
    int value;
    Node *next;
};

struct DoubleNode {
    int value;
    DoubleNode *next;
    DoubleNode *previous;
};

void (*FunPointer_SingleOne[3]) (Node**);            //function pointer
void (*FunPointer_SingleTwo[3]) (int, Node**);
void (*FunPointer_SingleThree[2]) (int, int, Node**);

void PrintList(Node**);
void PushFront(int, Node**);
void PushBack(int, Node**);
void DeleteNode(int, Node**);
void Clear(Node**);
void Reverse(Node**);
void PushBehind(int, int, Node**);
void PushAhead(int, int, Node**);

void PrintList_Double(DoubleNode**);
void PushFront_Double(int, DoubleNode**);
void PushBack_Double(int, DoubleNode**);
void DeleteNode_Double(int, DoubleNode**);
void Clear_Double(DoubleNode**);
void Reverse_Double(DoubleNode**);
void PushBehind_Double(int, int, DoubleNode**);
void PushAhead_Double(int, int, DoubleNode**);

int main(){

    FunPointer_SingleOne[0] = PrintList;
    FunPointer_SingleOne[1] = Clear;
    FunPointer_SingleOne[2] = Reverse;

    FunPointer_SingleTwo[0] = PushFront;
    FunPointer_SingleTwo[1] = PushBack;
    FunPointer_SingleTwo[2] = DeleteNode;

    FunPointer_SingleThree[0] = PushBehind;
    FunPointer_SingleThree[1] = PushAhead;

    cout << "Hello Single Linked List (with double pointer)!" << endl;

    Node *head = new Node();
    head->value = 0;
    head->next = NULL;


    PushBack(5, &head);
    PushBack(20, &head);
    PushBack(30, &head);
    PushFront(78, &head);
    PushFront(66, &head);
    PrintList(&head);

    Reverse(&head);
    PrintList(&head);

    Reverse(&head);
    PrintList(&head);

    PushBehind(15, 100, &head);
    PrintList(&head);

    PushBehind(30, 100, &head);
    PrintList(&head);

    PushAhead(1, 98, &head);
    PrintList(&head);

    PushAhead(5, 98, &head);
    PrintList(&head);

    DeleteNode(66 ,&head);
    PrintList(&head);

    DeleteNode(30, &head);
    PrintList(&head);

    Clear(&head);
    PrintList(&head);

    cout << endl << endl;

    cout << "Hello Single Linked List (with function pointer)!" << endl;

    FunPointer_SingleTwo[0](1, &head);
    FunPointer_SingleTwo[0](6, &head);
    FunPointer_SingleTwo[1](5, &head);
    FunPointer_SingleTwo[1](11, &head);
    FunPointer_SingleOne[0](&head);

    FunPointer_SingleTwo[2](6, &head);
    FunPointer_SingleOne[0](&head);

    FunPointer_SingleThree[0](5, 20, &head);
    FunPointer_SingleOne[0](&head);

    FunPointer_SingleThree[1](11, 39, &head);
    FunPointer_SingleOne[0](&head);

    FunPointer_SingleOne[2](&head);
    FunPointer_SingleOne[0](&head);

    FunPointer_SingleOne[1](&head);


    cout << endl << endl;

    cout << "Hello Double Linked List (with double pointer)!" << endl;

    DoubleNode *head_Double = NULL;

    PushBack_Double(30, &head_Double);
    PushBack_Double(1, &head_Double);
    PushBack_Double(2, &head_Double);
    PushBack_Double(9, &head_Double);
    PushBack_Double(13, &head_Double);
    PushFront_Double(87, &head_Double);
    PushFront_Double(101, &head_Double);
    PrintList_Double(&head_Double);

    DeleteNode_Double(10, &head_Double);
    PrintList_Double(&head_Double);

    DeleteNode_Double(13, &head_Double);
    PrintList_Double(&head_Double);

    DeleteNode_Double(30, &head_Double);
    PrintList_Double(&head_Double);

    PushBehind_Double(30, 1000, &head_Double);

    PushBehind_Double(9, 1000, &head_Double);
    PrintList_Double(&head_Double);

    PushBehind_Double(87, 50, &head_Double);
    PrintList_Double(&head_Double);

    PushAhead_Double(13, 2000, &head_Double);

    PushAhead_Double(101, 2000, &head_Double);
    PrintList_Double(&head_Double);

    PushAhead_Double(87, 60, &head_Double);
    PrintList_Double(&head_Double);

    Reverse_Double(&head_Double);

    Clear_Double(&head_Double);

    cout << endl << endl;

    cout << "Hello Double Linked List (with function pointer)!" << endl;  //TBD


    system("pause");
    return 0;
}

/*--------------------------------------------------------------------------------single linked list-------------------*/
void PrintList(Node **start){
    if (!start)
        cout << "List is empty." << endl;

    Node *current = *start;
    while (current != NULL) {
        cout << setw(5) << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void PushFront(int x, Node **start){
    Node *newNode = new Node();
    newNode->value = x;
    newNode->next = *start;
    *start = newNode;
    cout << "Add " << x << " in the front." << endl;
}

void PushBack(int x, Node **start){
    Node *newNode = new Node();
    newNode->value = x;

    if (*start == NULL)
        *start = newNode;

    Node *current = *start;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    cout << "Add " << x << " in the back." << endl;
}

void DeleteNode(int x, Node **start){
    Node *current = *start, *previous = NULL;

    while (current && current->value != x) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        cout << "There is no " << x << " in the list to be deleted." << endl;
        return;
    }
    else if (current == *start) {
        *start = (*start)->next;
        delete current;
        current = NULL;
    }
    else {
        previous->next = current->next;
        delete current;
        current = NULL;
    }
    cout << "Delete " << x << " from the list." << endl;
}

void Clear(Node **start){
    while (*start != NULL) {
        Node *current = *start;
        *start = (*start)->next;
        delete current;
        current = NULL;
    }
    if (*start == NULL) {
        cout << "Already clear all list!" << endl;
    }
}

void Reverse(Node **start){
    if (*start == NULL || (*start)->next == NULL) {
        cout << "List is empty or only one node, so it doesn't need to reverse." << endl;
        return;
    }

    Node *previous = NULL;
    Node *current = *start;
    Node *precede = (*start)->next;

    while (precede != NULL) {
        current->next = previous;
        previous = current;
        current = precede;
        precede = precede->next;
    }

    current->next = previous;
    *start = current;
    cout << "Reverse the list:" << endl;
}

void PushBehind(int target, int x, Node **start){
    Node *current = *start;
    Node *newNode = new Node();
    newNode->value = x;

    while (current && current->value != target) {
        current = current->next;
    }

    if (!current) {
        cout << "There is no " << target << " in the list to be push behind." << endl;
        return;
    }
    else {
        newNode->next = current->next;
        current->next = newNode;
    }
    cout << "Add " << x << " behind " << target << "." << endl;
}

void PushAhead(int target, int x, Node **start){
    Node *current = *start;
    Node *previous = NULL;
    Node *newNode = new Node();
    newNode->value = x;

    while (current && current->value != target) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        cout << "There is no " << target << " in the list to be push ahead." << endl;
        return;
    }
    else{
        newNode->next = current;
        previous->next = newNode;
    }
    cout << "Add " << x << " before " << target << "." << endl;
}

/*--------------------------------------------------------------------------------double linked list-------------------*/
void PrintList_Double(DoubleNode **start){
    DoubleNode *current = *start;

    if(*start == NULL){
        cout << "List is empty." << endl;
    }

    while (current) {
        cout << setw(5) << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void PushFront_Double(int x, DoubleNode **start){
    DoubleNode *newNode = new DoubleNode();
    newNode->value = x;

    newNode->next = *start;
    (*start)->previous = newNode;
    newNode->previous = NULL;
    *start = newNode;
    cout << "Add " << x << " in the front." << endl;
}

void PushBack_Double(int x, DoubleNode **start){
    DoubleNode *newNode = new DoubleNode();
    newNode->value = x;

    if (*start == NULL) {
        *start = newNode;
        return;
    }

    DoubleNode *current = *start;

    while (current->next) {
        current = current->next;
    }

    newNode->next = NULL;
    newNode->previous = current;
    current->next = newNode;

    cout << "Add " << x << " in the back." << endl;
}

void DeleteNode_Double(int x, DoubleNode **start){
    DoubleNode *current = *start;

    while (current && current->value != x) {
        current = current->next;
    }

    if (!current) {
        cout << "There is no " << x << " in the list to be deleted." << endl;
        return;
    }
    else if (current == *start) {
        *start = current->next;
        delete current;
        current = NULL;
    }
    else if (current->next == NULL) {
        current->previous->next = NULL;
        delete current;
        current = NULL;
    }
    else {
       current->previous->next = current->next;
       current->next->previous = current->previous;
       delete current;
       current = NULL;
    }

    cout << "Delete " << x << " from the list." << endl;
}

void Clear_Double(DoubleNode **start){
    DoubleNode *current = *start;

    while (*start) {
        current = *start;
        *start = (*start)->next;
        delete current;
        current = NULL;
    }
    if (*start == NULL) {
        cout << "Already clear all list!" << endl;
    }
}

void Reverse_Double(DoubleNode **start){
    DoubleNode *current = *start;

    if (!current->next) {
        cout << "Only one number:" << current->value << " ,don't need to reverse." << endl;
        return;
    }
    else if (!current) {
        cout << "The list is empty." << endl;
        return;
    }

    while (current->next) {
        current = current->next;
    }

    cout << "Reverse the list:" << endl;

    while (current) {
        cout << setw(5) << current->value << " ";
        current = current->previous;
    }
    cout << endl;
}

void PushBehind_Double(int target, int x, DoubleNode **start){
    DoubleNode *newNode = new DoubleNode();
    newNode->value = x;
    DoubleNode *current = *start;

    while (current && current->value != target) {
        current = current->next;
    }

    if (!current) {
        cout << "There is no " << target << " in the list for reference." << endl;
        return;
    }
    else if (!current->next) {  //last
        newNode->previous = current;
        current->next = newNode;
        newNode->next = NULL;
    }
    else {
        newNode->previous = current;
        newNode->next = current->next;
        current->next->previous = newNode;
        current->next = newNode;
    }

    cout << "Add " << x << " behind " << target << "." << endl;
}

void PushAhead_Double(int target, int x, DoubleNode **start){
    DoubleNode *newNode = new DoubleNode();
    newNode->value = x;
    DoubleNode *current = *start;

    while (current && current->value != target) {
        current = current->next;
    }

    if (!current) {
        cout << "There is no " << target << " in the list for reference." << endl;
        return;
    }
    else if (!current->previous) {  //first
        newNode->next = current;
        current->previous = newNode;
        newNode->previous = NULL;
        *start = newNode;
    }
    else {
        /*
        current->previous->next = newNode;
        newNode->previous = current->previous;
        newNode->next = current;
        current->previous = newNode;
        */
        //also can work!
        newNode->previous = current->previous;
        newNode->next = current;
        current->previous->next = newNode;
        current->previous = newNode;
    }

    cout << "Add " << x << " before " << target << "." << endl;
}

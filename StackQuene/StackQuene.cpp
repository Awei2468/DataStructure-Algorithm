#include <iostream>
#include <iomanip>
using namespace std;

struct StackNode {
    int value;
    StackNode *next;

    StackNode(int x):value(x),next(NULL){};
};

typedef struct StackList {
    int Size;
    StackNode *top ;

    StackList():Size(0), top(NULL){};
    void Push(int x);
    void Pop(void);
    bool IsEmpty(void);
    int GetTop(void);
    int GetSize(void);
} OneStackList;

void StackList::Push(int x){
    StackNode *newNode = new StackNode(x);

    if (!top)
        top = newNode;
    else {
        newNode->next = top;
        top = newNode;
    }

    Size++;
    cout << "Push " << setw(3) << x << " into Stack." << endl;
}

void StackList::Pop(void){
    StackNode *DeleteNode = top;

    if (!top) {
        cout << "Stack is empty." << endl;
        return;
    }
    else {
        cout << "Pop " << setw(3) << top->value << " from Stack." << endl;
        top = top->next;
        delete DeleteNode;
        DeleteNode = NULL;
        Size--;
    }
}

bool StackList::IsEmpty(void){
    cout << "Is Stack empty? ";

    if (!Size)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return (Size == 0);
}

int StackList::GetTop(void){
    if (!top) {
        cout << "Stack is empty, so no top value." << endl;
        return -1;
    }
    else
        return top->value;
}

int StackList::GetSize(void){
    return Size;
}

struct StackArray {
    int Top;
    int capacity;
    int *Array;

    StackArray():Top(-1), capacity(0), Array(NULL){};
    void IncreaseSize(void);
    void Push(int x);
    void Pop(void);
    bool IsEmpty(void);
    int GetTop(void);
    int GetSize(void);
};

void StackArray::IncreaseSize(void){
    int *newArray = new int[++capacity];

    for (int i = 0; i < capacity - 1; ++i) {
        newArray[i] = Array[i];
    }

    delete [] Array;
    Array = newArray;
}

void StackArray::Push(int x){
    if (Top + 1 ==  capacity)
        IncreaseSize();

    Array[++Top] = x;
    cout << "Push " << setw(3) << x << " into Stack." << endl;
}

void StackArray::Pop(void){
    if (IsEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Pop " << setw(3) << Array[Top--] << " from Stack." << endl;
    capacity--;
}

bool StackArray::IsEmpty(void){
    return (capacity == 0);
}

int StackArray::GetTop(void){
    if (IsEmpty()) {
        cout << "Stack is empty, so no top value." << endl;
        return -1;
    }
    return Array[Top];
}

int StackArray::GetSize(void){
    return capacity;
}

class QueueNode {
public:
    int value;
    QueueNode *next;

    QueueNode(int x):value(x),next(NULL){};
};

class QueueList {
public:
    QueueList():Front(NULL), Back(NULL), Size(0){};
    void Push(int x);
    void Pop(void);
    int getFront(void);
    int getBack(void);
    bool IsEmpty(void);
    int getSize(void);

private:
    QueueNode *Front, *Back;
    int Size;
};

void QueueList::Push(int x){
    QueueNode *newNode = new QueueNode(x);

    if (IsEmpty())
    {
        Front = newNode;
        Back = newNode;
    }
    else
    {
        Back->next = newNode;
        Back = newNode;
    }
    Size++;

    cout << "Push " << setw(3) << x << " into Queue." << endl;
}

void QueueList::Pop(void){
    QueueNode *deleteNode = Front;

    if (IsEmpty())
    {
        cout << "Quene is empty." << endl;
        return;
    }
    else
    {
        cout << "Pop " << setw(3) << deleteNode->value << " from Queue." << endl;
        Front = Front->next;
        delete deleteNode;
        deleteNode = NULL;
        Size--;
    }
}

int QueueList::getFront(void){
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    else
        return Front->value;
}

int QueueList::getBack(void){
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    else
        return Back->value;
}

bool QueueList::IsEmpty(void){
    return (Size == 0);
}

int QueueList::getSize(void){
    return Size;
}

class QueueArray {
public:
    QueueArray():capacity(0), Front(-1), Back(-1), Array(NULL){};
    void Push(int x);
    void Pop(void);
    int getFront(void);
    int getBack(void);
    bool IsEmpty(void);
    bool IsFull(void);
    void IncreaseSize(void);
    int getSize(void);

private:
    int capacity, Front, Back;
    int *Array;
};

void QueueArray::Push(int x){
    if (IsEmpty())
    {
        IncreaseSize();
        Array[++Back] = x;
        Front = Back;
    }
    else
    {
        if (IsFull())
        {
            IncreaseSize();
            Array[++Back] = x;
        }
        else
            Array[++Back] = x;
    }
    cout << "Push " << setw(3) << x << " into Queue." << endl;
}

void QueueArray::Pop(void){
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Pop " << setw(3) << Array[Front++] << " from Queue." << endl;
    capacity--;
}

int QueueArray::getFront(void){
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return Array[Front];
}

int QueueArray::getBack(void){
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return Array[Back];
}

bool QueueArray::IsEmpty(void){
    return (capacity == 0);
}

bool QueueArray::IsFull(void){
    return (Back == capacity-1);
}

void QueueArray::IncreaseSize(void){
    int *newArray = new int[++capacity];

    for (int i = 0; i < capacity - 1; ++i)
        newArray[i] = Array[i];

    delete [] Array;
    Array = newArray;
}

int QueueArray::getSize(void){
    return capacity;
}

int main(){

    cout << "Hello Stack(by LinkedList)!" << endl;

    OneStackList StackPractice;

    StackPractice.Push(5);
    StackPractice.Push(56);
    StackPractice.Push(100);
    cout << "top:" << StackPractice.GetTop() << "  " << "size:" << StackPractice.GetSize() << endl;

    cout << StackPractice.IsEmpty() << endl;

    StackPractice.Pop();
    StackPractice.Pop();
    cout << "top:" << StackPractice.GetTop() << "  " << "size:" << StackPractice.GetSize() << endl;

    StackPractice.Pop();
    cout << StackPractice.IsEmpty() << endl;
    cout << "top:" << StackPractice.GetTop() << "  " << "size:" << StackPractice.GetSize() << endl;

    cout << "--------------------------------------------" << endl;

    cout << "Hello Stack(by Array)!" << endl;

    StackArray StackPracticeArray;

    StackPracticeArray.Push(59);
    StackPracticeArray.Push(200);
    StackPracticeArray.Push(11);

    StackPracticeArray.IsEmpty();
    cout << "top:" << StackPracticeArray.GetTop() << " " << "size:" << StackPracticeArray.GetSize() << endl;

    StackPracticeArray.Pop();
    StackPracticeArray.Pop();

    StackPracticeArray.IsEmpty();
    cout << "top:" << StackPracticeArray.GetTop() << " " << "size:" << StackPracticeArray.GetSize() << endl;

    StackPracticeArray.Pop();

    StackPracticeArray.IsEmpty();
    cout << "top:" << StackPracticeArray.GetTop() << " " << "size:" << StackPracticeArray.GetSize() << endl;

    StackPracticeArray.Push(35);
    cout << "top:" << StackPracticeArray.GetTop() << " " << "size:" << StackPracticeArray.GetSize() << endl;

    StackPracticeArray.Pop();
    cout << "top:" << StackPracticeArray.GetTop() << " " << "size:" << StackPracticeArray.GetSize() << endl;

    cout << "--------------------------------------------" << endl;

    cout << "Hello Quene(by LinkedList)!" << endl;

    QueueList QueuePractice;

    QueuePractice.Push(59);
    QueuePractice.Push(61);
    QueuePractice.Push(70);

    cout << "front:" << QueuePractice.getFront() << " " << "back:" << QueuePractice.getBack() << " " << "size:" << QueuePractice.getSize() << endl;

    QueuePractice.Pop();
    QueuePractice.Pop();

    cout << "front:" << QueuePractice.getFront() << " " << "back:" << QueuePractice.getBack() << " " << "size:" << QueuePractice.getSize() << endl;

    QueuePractice.Pop();

    cout << "front:" << QueuePractice.getFront() << " " << "back:" << QueuePractice.getBack() << " " << "size:" << QueuePractice.getSize() << endl;

    cout << "--------------------------------------------" << endl;

    cout << "Hello Quene(by Array)!" << endl;

    QueueArray QueuePracticeArray;

    QueuePracticeArray.Push(102);
    QueuePracticeArray.Push(94);
    QueuePracticeArray.Push(300);
    QueuePracticeArray.Push(400);

    cout << "front:" << QueuePracticeArray.getFront() << " " << "back:" << QueuePracticeArray.getBack() << " " << "size:" << QueuePracticeArray.getSize() << endl;

    QueuePracticeArray.Pop();
    QueuePracticeArray.Pop();

    cout << "front:" << QueuePracticeArray.getFront() << " " << "back:" << QueuePracticeArray.getBack() << " " << "size:" << QueuePracticeArray.getSize() << endl;

    QueuePracticeArray.Pop();
    QueuePracticeArray.Pop();

    cout << "front:" << QueuePracticeArray.getFront() << " " << "back:" << QueuePracticeArray.getBack() << " " << "size:" << QueuePracticeArray.getSize() << endl;

    system("pause");
    return 0;
}

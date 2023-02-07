#include<iostream>
#include<climits>

using namespace std;

struct queue {
    int *list;
    int front = -1, back = -1;

    queue() {
        list = new int[10];
    }
    void Initial(int x);
    void Put(int x);
    int pop();
    int Get();
    bool IsEmpty();
    bool IsFull();
};

void queue::Initial(int x) {
    list = new int[x];
}

void queue::Put(int x) {
    if (IsFull()) {
        int *p = new int[++back];
        for (int i = 0; i < back-1; ++i)
            p[i] = list[i];
        list = p;
        delete [] p;
        p = NULL;   
    }
    else {
        if (front == -1)
            front++;
        ++back;
    }
    list[back] = x;
}

int queue::pop() {
    if (IsEmpty() || front > back)
        return INT_MIN;
    return list[front++];    
}

int queue::Get() {
    if (IsEmpty() || front > back)
        return INT_MIN;
    return list[front];
}

bool queue::IsEmpty() {
    return front == -1;
}

bool queue::IsFull() {
    return front == back-1;
}

int main() {

    struct queue myQueue;
    cout << myQueue.Get() << endl;
    myQueue.Initial(2);
    myQueue.Put(12);    
    myQueue.Put(20);
    cout << myQueue.Get() << endl;

    cout << "pop: " << myQueue.pop() << endl;
    cout << myQueue.Get() << endl;

    cout << "pop: " << myQueue.pop() << endl;
    cout << myQueue.Get() << endl;

    cout << "pop: " << myQueue.pop() << endl;
    cout << myQueue.Get() << endl;

    myQueue.Put(100);
    cout << myQueue.Get() << endl;

    system("pause");
    return 0;
}
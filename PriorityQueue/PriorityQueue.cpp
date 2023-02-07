#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>    //for floor,ceiling use

using namespace std;

struct HeapNode {
    int index,value;
    HeapNode():index(0),value(0){};
    HeapNode(int x, int y):index(x),value(y){};
};

class BinaryHeap {
public:
    vector<HeapNode> heap;
    void Swap(HeapNode &x, HeapNode &y);
    int FindPosition(int index);
    int GetParentNode(int index){ return (index-1) / 2; }

    void MinHeapify(int index, int length);
    void BuildMinHeap(vector<int> Array);
    void DecreaseValue(int index, int newValue);
    void MinHeapInsert(int index, int value);
    int Minimum(void);       //return index
    int ExtractMin(void);    //return index and change position
    void PrintList(void);

    BinaryHeap(){ heap.resize(1); }
    BinaryHeap(int n){ heap.resize(n); }
};

void BinaryHeap::MinHeapify(int index, int length) {
    int left = index*2 + 1, right = index*2 + 2, smallest;

    if (left < length && heap[left].value < heap[index].value)
        smallest = left;
    else
        smallest = index;

    if(right < length && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != index) {
        Swap(heap[smallest], heap[index]);
        MinHeapify(smallest, length);  //top down
    }
}

void BinaryHeap::BuildMinHeap(vector<int> Array) {  //buttom up
    for (int i = 0; i < Array.size(); ++i) {
        heap[i].index = i;
        heap[i].value = Array[i];
    }

    for (int i = (heap.size()-2)/2; i >= 0; --i) {
        MinHeapify(i, heap.size());
    }
}

void BinaryHeap::Swap(HeapNode &x, HeapNode &y) {
    HeapNode temp = x;
    x = y;
    y = temp;
}

int BinaryHeap::FindPosition(int index) {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i].index == index)
            return i;
    }
    return -1;
}

int BinaryHeap::Minimum(void) {
    return heap[0].index;
}

int BinaryHeap::ExtractMin(void) {
    if (!heap.size())
        return -1;

    int Min = heap[0].index;

    heap[0] = heap[heap.size()-1];
    heap.erase(heap.begin() + heap.size() - 1);  //erase last one
    MinHeapify(0, heap.size());  //top down

    return Min;
}

void BinaryHeap::DecreaseValue(int index, int newValue) {
    int index_check = FindPosition(index);

    if (newValue > heap[index_check].value) {
        cout << "New value is larger than current." << endl;
        return;
    }

    heap[index_check].value = newValue;

    while (heap[GetParentNode(index_check)].value > heap[index_check].value && index_check > 0) {  //bottom up
        Swap(heap[index_check], heap[GetParentNode(index_check)]);
        index_check = GetParentNode(index_check);
    }
}

void BinaryHeap::MinHeapInsert(int index,int value) {
    heap.push_back(HeapNode(index, value));
    DecreaseValue(index, value);  //buttom up
}

void BinaryHeap::PrintList(void) {
    for (int i = 0; i < heap.size(); ++i) {
        cout << setw(2) << "[" << heap[i].index << "]" << heap[i].value << " ";
    }
    cout << endl;
}


int main(){
    cout << "Hello Priority Queue!" << endl;

    vector<int> number = {3,1,20,5,7,13,25,6,55,14};

    BinaryHeap BH(number.size());

    BH.BuildMinHeap(number);
    BH.PrintList();

    BH.ExtractMin();
    BH.PrintList();

    BH.DecreaseValue(8,2);
    BH.PrintList();

    BH.MinHeapInsert(10,-2);
    BH.PrintList();

    cout << BH.Minimum() << endl;

    system("pause");
    return 0;
}

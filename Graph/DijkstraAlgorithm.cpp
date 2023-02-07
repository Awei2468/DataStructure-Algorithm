#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<math.h>

using namespace std;

struct HeapNode{

    int key, weight;
    HeapNode():key(0),weight(0){};
    HeapNode(int k, int w):key(k),weight(w){};

};

class BinaryHeap{

private:
    vector<HeapNode> heap;
    void Swap(HeapNode &x, HeapNode &y);

public:
    BinaryHeap(){heap.resize(1);};
    BinaryHeap(int n){heap.resize(n + 1);};

    void BuildMinHeap(vector<int> Array);
    void MinHeapify(int index, int length);
    int FindPosition(int index);
    int GetParentNode(int index){
        return floor(index/2);
    };
    void DecreaseValue(int index, int value);
    int ExtractMin(void);
    bool IsHeapEmpty(void){
        return (heap.size() <= 1);
    };

};

void BinaryHeap::Swap(HeapNode &x, HeapNode &y){

    HeapNode temp = x;
    x = y;
    y = temp;

}

void BinaryHeap::BuildMinHeap(vector<int> Array){

    for (int i = 0; i < Array.size(); ++i) {
        heap[i + 1].key = i;
        heap[i + 1].weight = Array[i];
    }

    for (int i = Array.size()/2; i >= 1; --i) {
        MinHeapify(i, Array.size() - 1);
    }

}

void BinaryHeap::MinHeapify(int index, int length){

    int left = index*2,
        right = index*2 + 1,
        smallest;

    if (left <= length && heap[left].weight < heap[index].weight)
        smallest = left;
    else
        smallest = index;

    if (right <= length && heap[right].weight < heap[smallest].weight)
        smallest = right;

    if (smallest != index) {
        Swap(heap[smallest],heap[index]);
        MinHeapify(smallest,length);
    }

}

int BinaryHeap::FindPosition(int index){

    int idx = 0;
    for (int i = 1; i < heap.size(); ++i) {
        if (heap[i].key == index) {
            idx = i;
            break;
        }
    }
    return idx;

}

void BinaryHeap::DecreaseValue(int index, int value){

    int index_check = FindPosition(index);


    if (value > heap[index_check].weight) {
        cout << "New value bigger than original value." << endl;
        return;
    }

    heap[index_check].weight = value;

    while (index_check > 1 && heap[GetParentNode(index_check)].weight > heap[index_check].weight) {
        Swap(heap[GetParentNode(index_check)], heap[index_check]);
        index_check = GetParentNode(index_check);
    }

}

int BinaryHeap::ExtractMin(void){

    if (IsHeapEmpty()) {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int Min = heap[1].key;
    heap[1] = heap[heap.size() - 1];
    heap.erase(heap.begin() + heap.size() - 1);
    MinHeapify(1, heap.size());

    return Min;

}

//-------------------------------------------------------------------------------------------

const int Max_distance = 1000;

class Graph_SP{

private:
    int node_number;
    vector<list<pair<int,int>>> Matrix;
    vector<int> pre, distance;
    vector<bool> visit;

public:
    Graph_SP():node_number(0){};
    Graph_SP(int n):node_number(n){

        Matrix.resize(n);

    }

    void AddEdge(int from, int to, int weight);
    void PrintArray(vector<int> Array);
    void Initialize(int start);
    void Relaxation(int from, int to, int weight);
    void Dijkstra(int start);

    friend class BinaryHeap;

};

void Graph_SP::AddEdge(int from, int to, int weight){

    Matrix[from].push_back(make_pair(to,weight));

}

void Graph_SP::PrintArray(vector<int> Array){

    for (int i = 0; i < node_number; ++i) {
        cout << setw(4) << i;
    }
    cout << endl;

    for (int i = 0; i < node_number; ++i) {
        cout << setw(4) << Array[i];
    }
    cout << endl;

}

void Graph_SP::Initialize(int start){

    pre.resize(node_number);
    distance.resize(node_number);
    visit.resize(node_number);

    for (int i = 0; i < node_number; ++i) {
        pre[i] = -1;
        distance[i] = Max_distance;
        visit[i] = false;
    }
    distance[start] = 0;

}

void Graph_SP::Relaxation(int from, int to, int weight){

    if (distance[to] > distance[from] + weight) {
        distance[to] = distance[from] + weight;
        pre[to] = from;
    }

}

void Graph_SP::Dijkstra(int start){

    Initialize(start);

    BinaryHeap minQueue(node_number);
    minQueue.BuildMinHeap(distance);

    while (!minQueue.IsHeapEmpty()) {
        int k = minQueue.ExtractMin();
        for (list<pair<int,int>>::iterator iter = Matrix[k].begin(); iter != Matrix[k].end(); ++iter) {
            Relaxation(k, (*iter).first, (*iter).second);
            minQueue.DecreaseValue((*iter).first, distance[(*iter).first]);
        }
    }

    cout << "pre=>" << endl;
    PrintArray(pre);

    cout << "distance=>" << endl;
    PrintArray(distance);

}



int main(){

    cout << "Dijkstra's algorithm." << endl;

    Graph_SP g1(6);

    g1.AddEdge(0, 1, 8); g1.AddEdge(0, 5, 1);
    g1.AddEdge(1, 0, 3); g1.AddEdge(1, 2, 1);
    g1.AddEdge(2, 0, 5); g1.AddEdge(2, 3, 2); g1.AddEdge(2, 4, 2);
    g1.AddEdge(3, 1, 4); g1.AddEdge(3, 2, 6); g1.AddEdge(3, 4, 7); g1.AddEdge(3, 5, 3);
    g1.AddEdge(5, 3, 2); g1.AddEdge(5, 4, 8);

    g1.Dijkstra(0);

    system("pause");
    return 0;
}

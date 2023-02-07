
#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>    //for floor,ceiling use
#include<list>

using namespace std;

struct HeapNode{

    int weight,element;
    HeapNode():weight(0),element(0){};
    HeapNode(int w, int e):weight(w),element(e){};

};

class BinaryHeap{

private:
    vector<HeapNode> heap;
    void Swap(struct HeapNode &n1,struct HeapNode &n2);

public:
    BinaryHeap(){heap.resize(1);};
    BinaryHeap(int n){heap.resize(n + 1);}

    void BuildMinHeap(vector<int> Array);
    void MinHeapify(int index, int length);
    void DecreaseValue(int index, int value);
    void MinHeapInsert(int index, int value);      //Base on DecreaseKey concept
    int ExtraceMin(void);                          //Extract minimum value and do MinHeapify
    int Minimum(void){return heap[1].element;};
    bool IsHeapEmpty(void){return heap.size() <= 1;};

    int FindPosition(int index);
    int GetParentNode(int index){return floor(index/2);};

};

int BinaryHeap::FindPosition(int index){

    int idx = 0;
    for (int i = 1; i < heap.size(); ++i) {
        if (heap[i].element == index) {
            idx = i;
            break;
        }
    }
    return idx;

}

void BinaryHeap::BuildMinHeap(vector<int> Array){

    for (int i = 0; i < Array.size(); ++i) {
        heap[i + 1].element = i;
        heap[i + 1].weight = Array[i];
    }

    for (int i = heap.size()/2; i >= 1; --i) {
        MinHeapify(i, heap.size() - 1);
    }

}

void BinaryHeap::MinHeapify(int index, int length){

    int left = 2*index, right = 2*index + 1, smallest;

    if (left <= length && heap[left].weight < heap[index].weight)
        smallest = left;
    else
        smallest = index;

    if (right <= length && heap[right].weight < heap[smallest].weight)
        smallest = right;

    if (smallest != index) {
        Swap(heap[smallest], heap[index]);
        MinHeapify(smallest, length);
    }

}

void BinaryHeap::Swap(struct HeapNode &n1,struct HeapNode &n2){

    struct HeapNode temp = n1;
    n1 = n2;
    n2 = temp;

}

void BinaryHeap::DecreaseValue(int index, int value){

    int index_check;
    index_check = FindPosition(index);

    if (value >= heap[index_check].weight){
        cout << "New value have to be small than original value." << endl;
        return;
    }

    heap[index_check].weight = value;

    while (index_check > 1 && heap[GetParentNode(index_check)].weight > heap[index_check].weight) {
        Swap(heap[GetParentNode(index_check)], heap[index_check]);
        index_check = GetParentNode(index_check);
    }

}

void BinaryHeap::MinHeapInsert(int index, int value){

    heap.push_back(HeapNode(value, index));
    DecreaseValue(index, value);

}

int BinaryHeap::ExtraceMin(void){

    if (IsHeapEmpty()) {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int Min = heap[1].element;
    heap[0] = heap[heap.size() - 1];
    heap.erase(heap.begin() + heap.size() - 1);
    MinHeapify(0, heap.size() - 1);

    return Min;

}

void Nothing(void){

    //--------------------------------------------------------------------------------------------------------------------------------------------

}

const int maxDistance = 1000;

class GraphMST{

private:
    int node_number;
    vector<vector<int>> Matrix;
    vector<int> pre, distance;
    vector<bool> visit;
    void InitializeValue(int start);
    void PrintArray(vector<int> Array);

public:
    GraphMST(void):node_number(0){};
    GraphMST(int n):node_number(n){

        Matrix.resize(node_number);
        for (int i = 0; i < node_number; ++i){
            Matrix[i].resize(node_number);
        }

    }


    void AddEdge(int from, int to, int weight);
    void PrimMinQueue(int start);

    friend class BinaryHeap;

};

void GraphMST::InitializeValue(int start){

    pre.resize(node_number);
    distance.resize(node_number);
    visit.resize(node_number);

    for (int i = 0; i < node_number; ++i) {
        pre[i] = -1;
        distance[i] = maxDistance;
        visit[i] = false;
    }

    distance[start] = 0;

}

void GraphMST::PrintArray(vector<int> Array){

    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << i;
    }

    cout << endl;

    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << Array[i];
    }

    cout << endl;

}

void GraphMST::AddEdge(int from, int to, int weight){

    Matrix[from][to] = weight;

}

void GraphMST::PrimMinQueue(int start){

    InitializeValue(start);

    BinaryHeap minQueue(node_number);
    minQueue.BuildMinHeap(distance);

    while (!minQueue.IsHeapEmpty()) {
        int u = minQueue.ExtraceMin();
        visit[u] = true;
        for (vector<vector<int>>::iterator iter = Matrix.begin(); iter != Matrix.end(); ++iter) {   //2 dimensions vector coding style
            for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); ++it) {
                if (!visit[*it] && Matrix[u][*it] < distance[*it] && Matrix[u][*it]) {
                    cout << "Matrix[u][*it], u=" << u << ", *it=" << *it << ", value=" << Matrix[u][*it] << endl;
                    distance[*it] = Matrix[u][*it];
                    pre[*it] = u;
                    minQueue.DecreaseValue(*it, distance[*it]);
                }
            }
        }
        /* //another easier expression
        for (int i = 0; i < node_number; ++i) {
            if (!visit[i] && Matrix[u][i] < distance[i] && Matrix[u][i]) {
                cout << "Matrix[u][i],u=" << u << ",i=" << i << ",value=" << Matrix[u][i] << endl;
                distance[i] = Matrix[u][i];
                pre[i] = u;
                minQueue.DecreaseValue(i, distance[i]);
            }
        }
        */
    }

    cout << "Print predecessor:" << endl;
    PrintArray(pre);
    cout << "Print distance:" << endl;
    PrintArray(distance);

    cout << setw(3) << "V1" << " - " << setw(3) << "V2" << " - " << setw(3) << "weight" << endl;
    int i = (start + 1) % node_number;
    while (i != start) {
        cout << setw(3) << pre[i] << " - " << setw(3) << i << " - " << setw(3) << distance[i] << endl;
        i = (++i) % node_number;
    }

}

int main(){

    cout << "Prim Algorithm by Min-Priority-Queue." << endl;

    GraphMST g6(7);

    g6.AddEdge(0, 1, 5); g6.AddEdge(0, 5, 3);
    g6.AddEdge(1, 0, 5); g6.AddEdge(1, 2, 10); g6.AddEdge(1, 4, 1); g6.AddEdge(1, 6, 4);
    g6.AddEdge(2, 1, 10); g6.AddEdge(2, 3, 5); g6.AddEdge(2, 6, 8);
    g6.AddEdge(3, 2, 5); g6.AddEdge(3, 4, 7); g6.AddEdge(3, 6, 9);
    g6.AddEdge(4, 1, 1); g6.AddEdge(4, 3, 7); g6.AddEdge(4, 5, 6); g6.AddEdge(4, 6, 2);
    g6.AddEdge(5, 0, 3); g6.AddEdge(5, 4, 6);
    g6.AddEdge(6, 1, 4); g6.AddEdge(6, 2, 8); g6.AddEdge(6, 3, 9); g6.AddEdge(6, 4, 2);


    g6.PrimMinQueue(2);

    system("pause");
    return 0;
}

/*
// C++ code
#include <iostream>
#include <vector>
#include <list>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()
#include <cmath>            // for std::floor

using std::cout;
using std::endl;

/////////////// MinHeap ////////////////

struct HeapNode{
    int key, element;
    HeapNode():key(0),element(0){};
    HeapNode(int key, int element):key(key),element(element){};
};
class BinaryHeap{
private:
    std::vector<HeapNode> heap;
    void swap(struct HeapNode &p1, struct HeapNode &p2);
    int FindPosition(int node);
    int GetParentNode(int node){return std::floor(node/2);};
public:
    BinaryHeap(){heap.resize(1);};
    BinaryHeap(int n){
        heap.resize(n + 1);          // 主要存放vertex及其distance的vector
    }
    // Min-Priority Queue
    void MinHeapify(int node, int length);
    void BuildMinHeap(std::vector<int> array);
    void DecreaseKey(int node, int newKey);
    void MinHeapInsert(int node, int key);
    int ExtractMin();                               // 回傳heap[1]並調整Heap
    int Minimum(){return heap[1].element;};         // 回傳heap[1]

    bool IsHeapEmpty(){return (heap.size()<=1);};

};

int BinaryHeap::FindPosition(int node){

    int idx = 0;
    for (int i = 1; i < heap.size(); i++) {
        if (heap[i].element == node) {
            idx = i;
        }
    }
    return idx;
}
void BinaryHeap::MinHeapInsert(int node, int key){

    heap.push_back(HeapNode(node,key));
    DecreaseKey(node, key);
}
void BinaryHeap::DecreaseKey(int node, int newKey){

    int index_node = FindPosition(node);      // 找到node所在的位置index

    if (newKey >= heap[index_node].key) {      // 如果不是把node的Key下修, 便終止此函式
        std::cout << "new key is not smaller than current key\n";
        return;
    }
    heap[index_node].key = newKey;            // 更新node之Key後,
                                              // 需要檢查是否新的subtree滿足Min Heap
    while (index_node > 1 && heap[GetParentNode(index_node)].key > heap[index_node].key) {
        swap(heap[index_node], heap[GetParentNode(index_node)]);
        index_node = GetParentNode(index_node);
    }
}
void BinaryHeap::swap(struct HeapNode &p1, struct HeapNode &p2){

    struct HeapNode temp = p1;
    p1 = p2;
    p2 = temp;
}
int BinaryHeap::ExtractMin(){

    if (IsHeapEmpty()) {
        std::cout << "error: heap is empty\n";
        exit(-1);
    }
    int min = heap[1].element;    // 此時heap的第一個node具有最小key值
    // 便以min記錄其element, 最後回傳min
    // delete the first element/vertex
    heap[1] = heap[heap.size()-1];            // 把最後一個element放到第一個位置,
    heap.erase(heap.begin()+heap.size()-1);   // 再刪除最後一個element
    MinHeapify(1, (int)heap.size());          // 目前, heap[1]具有最大Key, 需要進行調整

    return min;       // 回傳heap中具有最小key的element
}
void BinaryHeap::BuildMinHeap(std::vector<int> array){

    // 將array[]的資料放進 heap之矩陣中, 並預留 heap[0] 不做使用
    for (int i = 0; i < array.size(); i++) {
        heap[i + 1].element = i;                 // 把array[]的idx視為element
        heap[i + 1].key = array[i];              // 把array[]的數值視為key
    }
    for (int i = (int)heap.size()/2; i >= 1 ; i--) {
        MinHeapify(i, (int)heap.size()-1);     // length要減一, 因為heap從從1開始存放資料
    }
}
void BinaryHeap::MinHeapify(int node, int length){

    int left = 2*node,          // 取得left child
        right = 2*node + 1,     // 取得right child
        smallest;               // smallest用來記錄包含root與child, 三者之中Key最小的node

    if (left <= length && heap[left].key < heap[node].key)
        smallest = left;
    else
        smallest = node;

    if (right <= length && heap[right].key < heap[smallest].key)
        smallest = right;

    if (smallest != node) {                 // 如果目前node的Key不是三者中的最小
        swap(heap[smallest], heap[node]);   // 就調換node與三者中Key最小的node之位置
        MinHeapify(smallest, length);       // 調整新的subtree成Min Heap
    }
}

/////////////// Prim's Algorithm /////////////////

static const int maxDistance = 100;

class Graph_MST{
private:
    int num_vertex;
    std::vector<std::list<std::pair<int,int> > > AdjList;
    std::vector<int> predecessor, distance;
    std::vector<bool> visited;
    void InitializeSingleSource(int Start);       // 以Start作為起點
    void PrintDataArray(std::vector<int> array);
public:
    Graph_MST():num_vertex(0){};
    Graph_MST(int n):num_vertex(n){
        AdjList.resize(num_vertex);
    }
    void AddEdge(int from, int to, int weight);
    void Prim_MinQueue(int Start);

    friend class BinaryHeap;
};

void Graph_MST::InitializeSingleSource(int Start){

    distance.resize(num_vertex);
    predecessor.resize(num_vertex);

    for (int i = 0; i < num_vertex; i++) {
        distance[i] = maxDistance;
        predecessor[i] = -1;
    }
    distance[Start] = 0;      // 起點vertex的distance設為0, ExtractMin就會從起點開始
}

void Graph_MST::Prim_MinQueue(int Start){

    InitializeSingleSource(Start);

    BinaryHeap minQueue(num_vertex);
    minQueue.BuildMinHeap(distance);      // use minQueue to handle distance[]

    visited.resize(num_vertex, false);    // initializa visited[] as {0,0,0,...,0}

    while (!minQueue.IsHeapEmpty()) {
        int u = minQueue.ExtractMin();
        visited[u] = true;
        for (std::list<std::pair<int, int> >::iterator itr = AdjList[u].begin();
             itr != AdjList[u].end(); itr++) {
            if (visited[(*itr).first] == false && (*itr).second < distance[(*itr).first]) {

                // for edge(X,Y)
                // u: X , (*itr).first: Y, (*itr).second: weight(X,Y)
                // (*itr).second < distance[(*itr).first]: weight(X,Y) < distance[Y]

                distance[(*itr).first] = (*itr).second;
                predecessor[(*itr).first] = u;
                minQueue.DecreaseKey((*itr).first, distance[(*itr).first]);
            }
        }
    }
    ///////   print result   /////////

    cout << "print predecessor[]:\n";
    PrintDataArray(predecessor);
    cout << "print distance[]:\n";
    PrintDataArray(distance);

    cout << std::setw(3) << "v1" << " - " << std::setw(3) << "v2"<< " : weight\n";
    int i = (Start+1)%num_vertex;   // 若從4開始, i依序為5,6,0,1,2,3
    while (i != Start) {
        cout << std::setw(3) << predecessor[i] << " - " << std::setw(3) << i
        << " : " << std::setw(3) << distance[i] <<"\n";
        i = (++i)%num_vertex;       // 到了6之後, 6+1 = 7, error:bad_access
    }
}
void Graph_MST::PrintDataArray(std::vector<int> array){
    for (int i = 0; i < num_vertex; i++){
        cout << std::setw(4) << i;
    }
    std::cout << endl;
    for (int i = 0; i < num_vertex; i++){
        cout << std::setw(4) << array[i];
    }
    cout << endl << endl;
}
void Graph_MST::AddEdge(int from, int to, int weight){

    AdjList[from].push_back(std::make_pair(to,weight));
}

int main(){

    Graph_MST g6(7);

    g6.AddEdge(0, 1, 5);g6.AddEdge(0, 5, 3);
    g6.AddEdge(1, 0, 5);g6.AddEdge(1, 2, 10);g6.AddEdge(1, 4, 1);g6.AddEdge(1, 6, 4);
    g6.AddEdge(2, 1, 10);g6.AddEdge(2, 3, 5);g6.AddEdge(2, 6, 8);
    g6.AddEdge(3, 2, 5);g6.AddEdge(3, 4, 7);g6.AddEdge(3, 6, 9);
    g6.AddEdge(4, 1, 1);g6.AddEdge(4, 3, 7);g6.AddEdge(4, 5, 6);g6.AddEdge(4, 6, 2);
    g6.AddEdge(5, 0, 3);g6.AddEdge(5, 4, 6);
    g6.AddEdge(6, 1, 4);g6.AddEdge(6, 2, 8);g6.AddEdge(6, 3, 9);g6.AddEdge(6, 4, 2);

    cout << "MST found by Prim_MinQueue:\n";
    g6.Prim_MinQueue(2);

    return 0;
}
*/

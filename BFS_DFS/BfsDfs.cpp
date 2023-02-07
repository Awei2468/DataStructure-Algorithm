#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

class Graph {
public:
    int node_number;
    vector<vector<int>> List;
    int *distance,
        *pre,
        *color,
        *discover,
        *finish;

    Graph():node_number(0){};
    Graph(int N):node_number(N) {
        List.resize(node_number);
    };

    stack<int> s;   //use on topological sort

    void AddEdgeList(int from, int to);
    void BFS(int start);
    void DFS(int start);
    void DFSTraversal(int vertex, int &time);
    void DFS_ver2(int start);
    void DFSTraversal_ver2(int vertex);

    void Find_CC_BFS(int vertex);
    void Find_CC_DFS(int vertex);
    void SetCollapsing(int vertex);
    void PrintPre(void);

    void PrintSCC(int start);
    void PrintFinish(void);
    Graph GraphTranspose(void);
    void PrintNormalArray(int *Array);
    void TopologicalSort(int start);

    friend void Swap(int &x, int &y);
    friend int Partition(int *arr, int Front, int End, int *indexArr);
    friend void QuickSort(int *arr, int Front, int End, int *indexArr);
};

void Graph::AddEdgeList(int from, int to){
    List[from].push_back(to);
}

void Graph::BFS(int start){
    distance = new int[node_number];
    pre = new int[node_number];
    color  = new int[node_number];

    for (int i = 0; i < node_number; ++i) {  //initial value
        distance[i] = -1;
        pre[i] = -1;
        color[i] = 0;
    }

    queue<int> Q;
    int i = start;
    for (int k = 0; k < node_number; ++k) {
        if (color[i] == 0) { //while
            color[i] = 1;  //gray
            distance[i] = 0;
            pre[i] = -1;

            Q.push(i);
            while (!Q.empty()) {
                int u = Q.front();
                for (vector<int>::iterator iter = List[u].begin(); iter != List[u].end(); ++iter) {
                    if (color[*iter] == 0) { //white
                        color[*iter] = 1;  //gray
                        distance[*iter] = distance[u] + 1;
                        pre[*iter] = u;
                        Q.push(*iter);
                    }
                }
                Q.pop();
                color[u] = 2; //black
            }
        }
        i = k;  //for the case of more than one connected component
    }
}

void Graph::DFS(int start){
    color = new int[node_number];
    pre = new int[node_number];
    discover = new int[node_number];
    finish = new int[node_number];

    for (int i = 0; i < node_number; ++i) {  //initial value
        color[i] = 0;  //white
        pre[i] = -1;
        discover[i] = 0;
        finish[i] = 0;
    }

    int i = start;
    int time = 0;

    for (int k = 0; k < node_number; ++k) {
        if (color[i] == 0) {
            DFSTraversal(i, time);
        }
        i = k;  //for the case of more than one connected component
    }
}

void Graph::DFSTraversal(int vertex, int &time){
    color[vertex] = 1;  //gray
    discover[vertex] = ++time;

    for (vector<int>::iterator iter = List[vertex].begin(); iter != List[vertex].end(); ++iter) {
        if (color[*iter] == 0) {
            pre[*iter] = vertex;
            DFSTraversal(*iter, time);
        }
    }

    color[vertex] = 2; //black
    finish[vertex] = ++time;
    s.push(vertex);    //use on topological sort
}

void Graph::DFS_ver2(int start){
    color = new int[node_number];
    pre = new int[node_number];

    for (int i = 0; i < node_number; ++i) {  //initial value
        color[i] = 0;  //white
        pre[i] = -1;
    }

    int i = start;

    for (int k = 0; k < node_number; ++k) {
        if (color[i] == 0) {
            DFSTraversal_ver2(i);
        }
        i = k;  //for the case of more than one connected component
    }
}

void Graph::DFSTraversal_ver2(int vertex) {
    stack<int> S1;
    color[vertex] = 1;
    int tmp;
    
    S1.push(vertex);
    while (!S1.empty()) {
        tmp = S1.top();
        color[tmp] = 2;
        S1.pop();
        for (vector<int>::iterator iter = List[tmp].end()-1; iter >= List[tmp].begin(); --iter) {
            if (color[*iter] == 0) {
                pre[*iter] = tmp;
                color[*iter] = 1;
                S1.push(*iter);
            }
            else if (color[*iter] == 1)
                pre[*iter] = tmp;
        }
    }
}

void Graph::SetCollapsing(int vertex){
    int root;
    for (root = vertex; pre[root] >= 0; cout << vertex << ":" << pre[root] << " ", root = pre[root]);   //hard to think, print result help to recognize, to fint the root

    while (vertex != root) {
        int parent = pre[vertex];
        pre[vertex] = root;
        vertex = parent;
    }
}

void Graph::Find_CC_BFS(int vertex){
    BFS(vertex);
    cout << "Find connected component by BFS => " << endl;
    PrintPre();

    cout << "Set Collapsing=>";
    for (int i = 0; i < node_number; i++) {
        SetCollapsing(i);
    }
    cout << endl;

    PrintPre();

    int num_cc = 0;
    for (int i = 0; i < node_number; i++) {
        if (pre[i] < 0) {
            cout << "Component#" << ++num_cc << ": " << i << " ";
            for (int j = 0; j < node_number; j++) {
                if (pre[j] == i) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
}

void Graph::Find_CC_DFS(int vertex){
    DFS(vertex);
    cout << "Find connected component by DFS => " << endl;
    PrintPre();

    cout << "Set Collapsing=>";
    for (int i = 0; i< node_number; i++) {
        SetCollapsing(i);
    }
    cout << endl;

    PrintPre();

    int num_cc = 0;
    for (int i = 0; i < node_number; i++) {
        if (pre[i] < 0) {
            cout << "Component#" << ++num_cc << ": " << i << " ";
            for (int j = 0; j < node_number; j++) {
                if (pre[j] == i) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
}

void Graph::PrintPre(void){
    cout << "pre:" << endl;
    for (int i = 0; i < node_number; i++)
        cout << setw(3) << i;
    cout << endl;
    for (int i = 0; i < node_number; i++)
        cout << setw(3) << pre[i];
    cout << endl;
}

void Swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int Partition(int *arr, int Front, int End, int *indexArr){
    int pivot = arr[End];
    int i = Front-1;

    for (int j = Front; j < End; ++j) {
        if (arr[j] > pivot) {
            i++;
            Swap(arr[i],arr[j]);
            Swap(indexArr[i],indexArr[j]);
        }
    }

    Swap(arr[i+1],arr[End]);
    Swap(indexArr[i+1],indexArr[End]);

    return i+1;
}

void QuickSort(int *arr, int Front, int End, int *indexArr){  //need more familiar to it,O(n)=nlogn
    if (Front < End) {
        int pivot = Partition(arr,Front,End,indexArr);
        QuickSort(arr, Front, pivot-1, indexArr);
        QuickSort(arr, pivot+1, End, indexArr);
    }
}

void Graph::PrintSCC(int start){
    DFS(start); //first time DFS

    cout << "First DFS(),finish time:" << endl;  //print result
    PrintFinish();

    Graph gTransform(node_number);
    gTransform = GraphTranspose();

    int indexArray[node_number];  //must be array type, can't be pointer
    for (int i = 0; i < node_number; ++i) {
        indexArray[i] = i;
    }

    QuickSort(finish, 0, node_number-1, indexArray);  //sort from big to small

    cout << "Finish time sort from big to small:" << endl;
    PrintNormalArray(indexArray);

    /*initialize start------------------------------also can be wrapped as a function*/
    gTransform.color = new int[node_number];
    gTransform.discover = new int[node_number];
    gTransform.finish = new int[node_number];
    gTransform.pre = new int[node_number];

    for (int i = 0; i < node_number; ++i) {
        gTransform.color[i] = 0;
        gTransform.discover[i] = 0;
        gTransform.finish[i] = 0;
        gTransform.pre[i] = -1;
    }
    /*initialize finish-----------------------------also can be wrapped as a function*/

    int time = 0;
    for (int i = 0; i < node_number; ++i) {
        if (gTransform.color[indexArray[i]] == 0) {
            gTransform.DFSTraversal(indexArray[i], time);
        }
    }

    cout << "Second DFS(),finish time:" << endl;  //print result
    gTransform.PrintFinish();

    cout << "pre before set collapsing:" << endl;
    gTransform.PrintPre();

    cout << "Set Collapsing=>";
    for (int i = 0; i < node_number; ++i)
        gTransform.SetCollapsing(i);
    cout << endl;

    cout << "pre after set collapsing:" << endl;
    gTransform.PrintPre();

    int num_cc = 0;
    for (int i = 0; i < node_number; ++i) {
        if (gTransform.pre[i] < 0) {
            cout << "SCC#" << ++num_cc << ":" << i << " ";
            for (int j = 0; j < node_number; ++j){
                if (gTransform.pre[j] == i)
                    cout << j << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

void Graph::PrintFinish(void){
    cout << "finish:" << endl;
    for (int i = 0; i < node_number; i++)
        cout << setw(3) << i;
    cout << endl;
    for (int i = 0; i < node_number; i++)
        cout << setw(3) << finish[i];
    cout << endl;
}

void Graph::PrintNormalArray(int *Array){
    cout << "Normal Array:" << endl;
    for (int i = 0; i < node_number; i++)
        cout << setw(3) << i;
    cout << endl;
    for (int i = 0; i < node_number; i++)
        cout << setw(3) << Array[i];
    cout << endl;
}

Graph Graph::GraphTranspose(void){
    Graph gT(node_number);

    for (int i = 0; i < node_number; ++i) {
        for (vector<int>::iterator iter = List[i].begin(); iter != List[i].end(); ++iter) {
            gT.AddEdgeList(*iter,i);
        }
    }

    return gT;
}

void Graph::TopologicalSort(int start){
    DFS(start);

    while (!s.empty()) {
        cout << setw(2) << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int  main(){

    cout << "Hello BFS." << endl;

    Graph g1(9);

    //build graph
    g1.AddEdgeList(0,1); g1.AddEdgeList(0,2); g1.AddEdgeList(0,3);
    g1.AddEdgeList(1,0); g1.AddEdgeList(1,4);
    g1.AddEdgeList(2,0); g1.AddEdgeList(2,4); g1.AddEdgeList(2,5); g1.AddEdgeList(2,6); g1.AddEdgeList(2,7);
    g1.AddEdgeList(3,0); g1.AddEdgeList(3,7);
    g1.AddEdgeList(4,1); g1.AddEdgeList(4,2); g1.AddEdgeList(4,5);
    g1.AddEdgeList(5,2); g1.AddEdgeList(5,4); g1.AddEdgeList(5,8);
    g1.AddEdgeList(6,2); g1.AddEdgeList(6,7); g1.AddEdgeList(6,8);
    g1.AddEdgeList(7,2); g1.AddEdgeList(7,3); g1.AddEdgeList(7,6);
    g1.AddEdgeList(8,5); g1.AddEdgeList(8,6);

    g1.BFS(0);


    for (int i = 0; i < g1.node_number; ++i) {
        cout << "color[" << i << "]:" << g1.color[i] << ", " << "distance[" << i << "]:" << g1.distance[i] << ", " << "pre[" << i << "]:" << g1.pre[i] << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "Hello DFS." << endl;

    Graph g2(12);

    g2.AddEdgeList(0,1); g2.AddEdgeList(0,2); g2.AddEdgeList(0,3);
    g2.AddEdgeList(1,0); g2.AddEdgeList(1,4);
    g2.AddEdgeList(2,0); g2.AddEdgeList(2,4); g2.AddEdgeList(2,5); g2.AddEdgeList(2,6); g2.AddEdgeList(2,7);
    g2.AddEdgeList(3,0); g2.AddEdgeList(3,7);
    g2.AddEdgeList(4,1); g2.AddEdgeList(4,2); g2.AddEdgeList(4,5);
    g2.AddEdgeList(5,2); g2.AddEdgeList(5,4); g2.AddEdgeList(5,8);
    g2.AddEdgeList(6,2); g2.AddEdgeList(6,7); g2.AddEdgeList(6,8);
    g2.AddEdgeList(7,2); g2.AddEdgeList(7,3); g2.AddEdgeList(7,6);
    g2.AddEdgeList(8,5); g2.AddEdgeList(8,6);                     //same with above graph until this statement
    g2.AddEdgeList(9,8);
    g2.AddEdgeList(10,9); g2.AddEdgeList(10,11);
    g2.AddEdgeList(11,10);

    g2.DFS(0);

    for (int i = 0; i < g2.node_number; ++i) {
        cout << "color[" << i << "]:" << g2.color[i] << ", " << "pre[" << i << "]:" << g2.pre[i] << ", " << "discover[" << i << "]:" << g2.discover[i] << ", " << "finish[" << i << "]:" << g2.finish[i] << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "DFS by pure stack!" << endl;

    Graph g6(12);

    g6.AddEdgeList(0,1); g6.AddEdgeList(0,2); g6.AddEdgeList(0,3);
    g6.AddEdgeList(1,0); g6.AddEdgeList(1,4);
    g6.AddEdgeList(2,0); g6.AddEdgeList(2,4); g6.AddEdgeList(2,5); g6.AddEdgeList(2,6); g6.AddEdgeList(2,7);
    g6.AddEdgeList(3,0); g6.AddEdgeList(3,7);
    g6.AddEdgeList(4,1); g6.AddEdgeList(4,2); g6.AddEdgeList(4,5);
    g6.AddEdgeList(5,2); g6.AddEdgeList(5,4); g6.AddEdgeList(5,8);
    g6.AddEdgeList(6,2); g6.AddEdgeList(6,7); g6.AddEdgeList(6,8);
    g6.AddEdgeList(7,2); g6.AddEdgeList(7,3); g6.AddEdgeList(7,6);
    g6.AddEdgeList(8,5); g6.AddEdgeList(8,6);                     //same with above graph until this statement
    g6.AddEdgeList(9,8);
    g6.AddEdgeList(10,9); g6.AddEdgeList(10,11);
    g6.AddEdgeList(11,10);

    g6.DFS_ver2(0);

    for (int i = 0; i < g6.node_number; ++i) {
        cout << "color[" << i << "]:" << g6.color[i] << ", " << "pre[" << i << "]:" << g6.pre[i] << endl;
    }

    cout << "-----------------------------------------------------------" << endl;

    cout << "Find connected component." << endl;

    Graph g3(9);

    g3.AddEdgeList(0, 1);
    g3.AddEdgeList(1, 0); g3.AddEdgeList(1, 4); g3.AddEdgeList(1, 5);
    // AdjList[2] empty
    g3.AddEdgeList(3, 6);
    g3.AddEdgeList(4, 1); g3.AddEdgeList(4, 5);
    g3.AddEdgeList(5, 1); g3.AddEdgeList(5, 4); g3.AddEdgeList(5, 7);
    g3.AddEdgeList(6, 3); g3.AddEdgeList(6, 8);
    g3.AddEdgeList(7, 5);
    g3.AddEdgeList(8, 6);

    g3.Find_CC_BFS(0);
    cout << endl;

    g3.Find_CC_DFS(0);
    cout << endl;

    cout << "-----------------------------------------------------------" << endl;

    cout << "Find strong connected component." << endl;

    Graph g4(9);

    g4.AddEdgeList(0,1);
    g4.AddEdgeList(1,2); g4.AddEdgeList(1,4);
    g4.AddEdgeList(2,0); g4.AddEdgeList(2,3); g4.AddEdgeList(2,5);
    g4.AddEdgeList(3,2);
    g4.AddEdgeList(4,5); g4.AddEdgeList(4,6);
    g4.AddEdgeList(5,4); g4.AddEdgeList(5,6); g4.AddEdgeList(5,7);
    g4.AddEdgeList(6,7);
    g4.AddEdgeList(7,8);
    g4.AddEdgeList(8,6);

    cout << "Vertex(0) is starting point =>" << endl;
    g4.PrintSCC(0);
    cout << "Vertex(4) is starting point =>" << endl;
    g4.PrintSCC(4);

    cout << "-----------------------------------------------------------" << endl;

    cout << "Show topological sort." << endl;

    Graph g5(15);

    g5.AddEdgeList(0,2);
    g5.AddEdgeList(1,2);
    g5.AddEdgeList(2,6); g5.AddEdgeList(2,7);
    g5.AddEdgeList(3,4);
    g5.AddEdgeList(4,5);
    g5.AddEdgeList(5,6); g5.AddEdgeList(5,14);
    g5.AddEdgeList(6,8); g5.AddEdgeList(6,9); g5.AddEdgeList(6,11); g5.AddEdgeList(6,12);
    g5.AddEdgeList(7,8);
    g5.AddEdgeList(9,10);
    g5.AddEdgeList(12,13);

    g5.TopologicalSort(0);
    g5.TopologicalSort(4);


    system("pause");
    return 0;
}

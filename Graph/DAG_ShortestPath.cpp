#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>

using namespace std;

const int Max_distance = 1000;

class Graph_SP{

private:
    int node_number;
    vector<list<pair<int,int>>> Matrix;
    vector<int> pre, distance;
    vector<int> color, discover, finish;

public:
    Graph_SP():node_number(0){};
    Graph_SP(int n):node_number(n){

        Matrix.resize(n);

    }

    stack<int> S_topology;

    void AddEdge(int from, int to, int weight);
    void PrintArray(vector<int> Array);

    void Initialize(int start);
    void Relaxation(int from, int to, int weight);
    void DAG_SP(int start);
    void DoTopologicalSort(stack<int> &S, int start);
    void DFSVisit(stack<int> &S, vector<int> &color, vector<int> &discover, vector<int> &finish, int &vertex, int &time, int &total_node_index);

};

void Graph_SP::AddEdge(int from, int to, int weight){

    Matrix[from].push_back(make_pair(to,weight));

}

void Graph_SP::PrintArray(vector<int> Array){

    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;

    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << Array[i];
    }
    cout << endl;

}

void Graph_SP::Initialize(int start){

    pre.resize(node_number);
    distance.resize(node_number);
    color.resize(node_number);
    discover.resize(node_number);
    finish.resize(node_number);

    for (int i = 0; i < node_number; ++i) {
        pre[i] = -1;
        distance[i] = Max_distance;
        color[i] = 0;
        discover[i] = 0;
        finish[i] = 0;
    }

    distance[start] = 0;

}

void Graph_SP::Relaxation(int from, int to, int weight){

    if (distance[to] > distance[from] + weight) {
        distance[to] = distance[from] + weight;
        pre[to] = from;
    }

}

void Graph_SP::DFSVisit(stack<int> &S, vector<int> &color, vector<int> &discover, vector<int> &finish, int &vertex, int &time, int &total_node_index){

    color[vertex] = 1;  //gray
    discover[vertex] = ++time;

    for (list<pair<int,int>>::iterator iter = Matrix[vertex].begin(); iter != Matrix[vertex].end(); ++iter) {
        if (color[(*iter).first] == 0) {
            pre[(*iter).first] = vertex;
            DFSVisit(S, color, discover, finish, (*iter).first, time, total_node_index);
        }
    }

    color[vertex] = 2;  //black
    finish[vertex] = ++time;
    S.push(vertex);

}

void Graph_SP::DoTopologicalSort(stack<int> &S, int start){

    int time = 0, total_node_index = node_number-1, i = start;

    for (int j = 0; j < node_number; ++j) {
        if (color[j] == 0) {
            DFSVisit(S_topology, color, discover, finish, i, time, total_node_index);
        }
        i = j;
    }

    cout << "discover vector=>" << endl;
    PrintArray(discover);
    cout << "finish vector=>" << endl;
    PrintArray(finish);

}

void Graph_SP::DAG_SP(int start){

    Initialize(start);

    DoTopologicalSort(S_topology, start);

    while (!S_topology.empty()) {
        for (list<pair<int,int>>::iterator iter = Matrix[S_topology.top()].begin(); iter != Matrix[S_topology.top()].end(); ++iter) {
            Relaxation(S_topology.top(), (*iter).first, (*iter).second);
        }
        S_topology.pop();
    }

    cout << "predecessor=>" << endl;
    PrintArray(pre);
    cout << "distance=>" << endl;
    PrintArray(distance);

}

int main(){

    cout << "DAG(directed acyclic graph) find shortest path." << endl;

    Graph_SP g1(7);

    g1.AddEdge(0, 1, 3); g1.AddEdge(0, 2, -2);
    g1.AddEdge(1, 3, -4); g1.AddEdge(1, 4, 4);
    g1.AddEdge(2, 4, 5); g1.AddEdge(2, 5, 6);
    g1.AddEdge(3, 5, 8); g1.AddEdge(3, 6, 2);
    g1.AddEdge(4, 3, -3); g1.AddEdge(4, 6, -2);
    g1.AddEdge(5, 6, 2);

    g1.DAG_SP(0);

    system("pause");
    return 0;
}

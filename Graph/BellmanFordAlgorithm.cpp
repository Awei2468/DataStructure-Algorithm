#include<iostream>
#include<iomanip>
#include<vector>
#include<list>

using namespace std;

const int Max_distance = 1000;

class Bellman_Ford{

private:
    int node_number;
    vector<list<pair<int,int>>> Matrix;
    vector<int> pre, distance;
public:
    Bellman_Ford():node_number(0){};
    Bellman_Ford(int n):node_number(n){

        Matrix.resize(n);

    }
    void AddEdge(int from, int to, int weight);
    void PrintArray(vector<int> Array);
    void Initialize(int start);
    void Relaxation(int from, int to, int weight);
    bool BellmanFord_Algorithm(int start);

};

void Bellman_Ford::AddEdge(int from, int to, int weight){

    Matrix[from].push_back(make_pair(to,weight));

}

void Bellman_Ford::PrintArray(vector<int> Array){

    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << i << " ";
    }

    cout << endl;

    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << Array[i] << " ";
    }

    cout << endl;

}

void Bellman_Ford::Initialize(int start){

    pre.resize(node_number);
    distance.resize(node_number);

    for (int i = 0; i < node_number; ++i) {
        pre[i] = -1;
        distance[i] = Max_distance;
    }

    distance[start] = 0;

}

void Bellman_Ford::Relaxation(int from, int to, int weight){

    if (distance[to] > distance[from] + weight) {
        distance[to] = distance[from] + weight;
        pre[to] = from;
    }

}

bool Bellman_Ford::BellmanFord_Algorithm(int start){

    Initialize(start);

    for (int i = 0; i < node_number-1; ++i) {    //|V|-1
        for (int j = 0; j < node_number; ++j) {
            for (list<pair<int,int>>::iterator iter = Matrix[j].begin(); iter != Matrix[j].end(); ++iter) {
                Relaxation(j, (*iter).first, (*iter).second);
            }
        }
    }

    cout << "predecessor=>" << endl;
    PrintArray(pre);

    cout << "distance=>" << endl;
    PrintArray(distance);

    //check whether have negative cycle
    for (int i = 0; i < node_number; ++i) {
        for (list<pair<int,int>>::iterator iter = Matrix[i].begin(); iter != Matrix[i].end(); ++iter) {
            if (distance[(*iter).first] > distance[i] + (*iter).second)
                return false;
        }
    }
    return true;

}

int main() {

    cout << "Hello Bellman-Ford Algorithm." << endl;

    Bellman_Ford B1(6);

    B1.AddEdge(0,1,5);
    B1.AddEdge(1,2,6); B1.AddEdge(1,4,-4);
    B1.AddEdge(2,4,-3); B1.AddEdge(2,5,-2);
    B1.AddEdge(3,2,4);
    B1.AddEdge(4,3,1); B1.AddEdge(4,5,6);
    B1.AddEdge(5,0,3); B1.AddEdge(5,1,7);

    if (B1.BellmanFord_Algorithm(0))
        cout << "Not a negative cycle." << endl;
    else
        cout << "Is a negative cycle." << endl;


    system("pause");
    return 0;
}

#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<math.h>

using namespace std;

const int maxDistance = 1000;

class Graph_SP{

private:
    int node_number;
    vector<vector<int>> Matrix, distance, pre;

public:
    Graph_SP():node_number(0){};
    Graph_SP(int n):node_number(n){

        Matrix.resize(n);
        for (int i = 0; i < node_number; ++i) {
            Matrix[i].resize(node_number,maxDistance);
            for (int j = 0; j < node_number; ++j) {
                if (i == j)
                    Matrix[i][j] = 0;
            }
        }

    };
    void AddEdge(int from, int to, int weight);
    void PrintData(vector<vector<int>> A);
    void Initialize(void);
    void FloydWarshall(void);

};

void Graph_SP::Initialize(void){

    distance.resize(node_number);
    pre.resize(node_number);

    for (int i = 0; i < node_number; ++i) {
        distance[i].resize(node_number);
        pre[i].resize(node_number, -1);
        for (int j = 0; j < node_number; ++j) {
            distance[i][j] = Matrix[i][j];
            if (distance[i][j] != 0 && distance[i][j] != maxDistance) {
                pre[i][j] = i;
            }
        }
    }

}

void Graph_SP::AddEdge(int from, int to, int weight){

    Matrix[from][to] = weight;

}

void Graph_SP::PrintData(vector<vector<int>> A){

    for (int i = 0; i < node_number; ++i) {
        for (int j = 0; j < node_number; ++j) {
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }

}

void Graph_SP::FloydWarshall(void){

    Initialize();

    cout << "Initial distance:" << endl;
    PrintData(distance);
    cout << "Initial predecessor:" << endl;
    PrintData(pre);

    for (int k = 0; k < node_number; ++k) {
        cout << "Include vertex: " << k << endl;
        for (int i = 0; i < node_number; ++i) {
            for (int j = 0; j < node_number; ++j) {
                if (distance[i][j] > distance[i][k] + distance[k][j] && distance[i][k] != maxDistance && distance[k][j] != maxDistance) {  //some edge only one direction, so maxDistance express unlimited
                    distance[i][j] = distance[i][k] + distance[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }

        cout << "distance:" << endl;
        PrintData(distance);
        cout << "predecessor:" << endl;
        PrintData(pre);
    }

}

int main(){

    cout << "Floyd Warshall Algorithm." << endl;

    Graph_SP g1(4);

    g1.AddEdge(0, 1, 2); g1.AddEdge(0, 2, 6); g1.AddEdge(0, 3, 8);
    g1.AddEdge(1, 2, -2); g1.AddEdge(1, 3, 3);
    g1.AddEdge(2, 0, 4); g1.AddEdge(2, 3, 1);

    g1.FloydWarshall();

    system("pause");
    return 0;
}

#include<iostream>
#include<iomanip>    //for setw
#include<vector>
#include<algorithm>  //for sort

using namespace std;

const int Max_Weight = 10000;

class GraphMST {
private:
    int node_number;
    vector<vector<int>> Matrix;
public:
    GraphMST():node_number(0){};
    GraphMST(int n):node_number(n){
        Matrix.resize(node_number);
        for (int i = 0; i < node_number; ++i) {
            Matrix[i].resize(node_number);
        }
    }
    void AddEdge(int from, int to, int weight);
    void PrimMST(int start);
    friend int MinKeyExtract(int *key, bool *visit, int Size);
};

int MinKeyExtract(int *key, bool *visit, int Size) {
    int Min = Max_Weight, min_index = 0;
    for (int i = 0; i < Size; ++i) {
        if (!visit[i] && key[i] < Min) {  //avoid cycle
            Min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void GraphMST::PrimMST(int start) {
    int key[node_number];
    int pre[node_number];
    bool visit[node_number];

    for (int i = 0; i < node_number; ++i) {
        key[i] = Max_Weight;
        pre[i] = -1;
        visit[i] = false;
    }

    key[start] = 0;
    for (int i = 0; i < node_number; ++i) {
        int p = MinKeyExtract(key, visit, node_number);
        visit[p] = true;
        for (int j = 0; j < node_number; ++j) {
            if (!visit[j] && Matrix[p][j] && Matrix[p][j] < key[j]) {
                pre[j] = p;
                key[j] = Matrix[p][j];
            }
        }
    }
    //print result
    cout << setw(3) << "V1" << " - " << setw(3) << "V2" << " - " << "Weight" << endl;
    int i = (start + 1) % node_number;
    while (i != start) {
        cout << setw(3) << pre[i] << " - " << setw(3) << i << " - " << setw(3) << Matrix[pre[i]][i] << endl;
        i = (++i) % node_number;
    }
}

void GraphMST::AddEdge(int from, int to, int weight) {
    Matrix[from][to] = weight;
}

int main(){
    cout << "Prim Algorithm!" << endl;

    GraphMST g1(7);
    g1.AddEdge(0, 1, 5); g1.AddEdge(0, 5, 3);
    g1.AddEdge(1, 0, 5); g1.AddEdge(1, 2, 10); g1.AddEdge(1, 4, 1); g1.AddEdge(1, 6, 4);
    g1.AddEdge(2, 1, 10); g1.AddEdge(2, 3, 5); g1.AddEdge(2, 6, 8);
    g1.AddEdge(3, 2, 5); g1.AddEdge(3, 4, 7); g1.AddEdge(3, 6, 9);
    g1.AddEdge(4, 1, 1); g1.AddEdge(4, 3, 7); g1.AddEdge(4, 5, 6); g1.AddEdge(4, 6, 2);
    g1.AddEdge(5, 0, 3); g1.AddEdge(5, 4, 6);
    g1.AddEdge(6, 1, 4); g1.AddEdge(6, 2, 8); g1.AddEdge(6, 3, 9); g1.AddEdge(6, 4, 2);

    g1.PrimMST(5);  //start vertex

    system("pause");
    return 0;
}

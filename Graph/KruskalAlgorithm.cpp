#include<iostream>
#include<iomanip>    //for setw
#include<vector>
#include<algorithm>  //for sort

using namespace std;

struct Edge {
    int from, to, weight;
    Edge(){};
    Edge(int f, int t, int w):from(f),to(t),weight(w){};
};

class GraphMST {
public:
    int node_num;
    vector<vector<int>> Matrix;

    GraphMST():node_num(0){};
    GraphMST(int n):node_num(n){
        Matrix.resize(n);
        for (int i = 0; i < node_num; ++i){
            Matrix[i].resize(n);
        }
    }

    void AddEdge(int from, int to, int weight);

    void KruskalMST(void);
    void GetSortedEdge(vector<Edge> &edgeArray);
    friend int FindCollapsing(int *pre, int i);
    friend void UnionSet(int *pre, int x, int y);
};

int FindCollapsing(int *pre, int i){
    int root;
    for (root = i; pre[root] >= 0; root = pre[root]);

    while (i != root){
        int parent = pre[i];
        pre[i] = root;
        i = parent;
    }

    return root;
}

void UnionSet(int *pre, int x, int y){
    int xroot = FindCollapsing(pre,x);
    int yroot = FindCollapsing(pre,y);

    if (xroot <= yroot){
        pre[xroot] += pre[yroot];
        pre[yroot] = xroot;
    }
    else{
        pre[yroot] += pre[xroot];
        pre[xroot] = yroot;
    }
}

bool WeightCompare(Edge e1, Edge e2){
    return (e1.weight < e2.weight);
}

void GraphMST::GetSortedEdge(vector<Edge> &edgeArray){   //call by address
    for (int i = 0; i < node_num; ++i){
        for (int j = i+1; j <node_num; ++j){
            if (Matrix[i][j] != 0)
                edgeArray.push_back(Edge(i,j,Matrix[i][j]));
        }
    }

    sort(edgeArray.begin(),edgeArray.end(),WeightCompare);
}

void GraphMST::AddEdge(int from, int to, int weight){
    Matrix[from][to] = weight;
}

void GraphMST::KruskalMST(void){
    Edge *edgeSetMST = new Edge[node_num - 1];
    int edgeCount = 0;

    int pre[node_num];
    for (int i = 0; i < node_num; ++i) {
        pre[i] = -1;
    }

    vector<Edge> increaseWeight;
    GetSortedEdge(increaseWeight);

    for (int i = 0; i < increaseWeight.size(); ++i) {
        if (FindCollapsing(pre, increaseWeight[i].from) != FindCollapsing(pre, increaseWeight[i].to)) {
            edgeSetMST[edgeCount++] = increaseWeight[i];
            UnionSet(pre, increaseWeight[i].from, increaseWeight[i].to);
        }
    }

    //print result
    cout << setw(3) << "V1" << " - " << setw(3) << "V2" << " - " << "weight" << endl;
    for (int i = 0; i < edgeCount; ++i) {
        cout << setw(3) << edgeSetMST[i].from << " - " << setw(3) << edgeSetMST[i].to << " - " << setw(3) << edgeSetMST[i].weight << endl;
    }

    delete [] edgeSetMST;
}

int main(){

    cout << "Kruskal Algorithm!" << endl;

    GraphMST g1(7);
    g1.AddEdge(0,1,5); g1.AddEdge(0,5,3);
    g1.AddEdge(1,0,5); g1.AddEdge(1,2,10); g1.AddEdge(1,4,1); g1.AddEdge(1,6,4);
    g1.AddEdge(2,1,10); g1.AddEdge(2,3,5); g1.AddEdge(2,6,8);
    g1.AddEdge(3,2,5); g1.AddEdge(3,4,7); g1.AddEdge(3,6,9);
    g1.AddEdge(4,1,1); g1.AddEdge(4,3,7); g1.AddEdge(4,5,6); g1.AddEdge(4,6,2);
    g1.AddEdge(5,0,3); g1.AddEdge(5,4,6);
    g1.AddEdge(6,1,4); g1.AddEdge(6,2,8); g1.AddEdge(6,3,9); g1.AddEdge(6,4,2);

    g1.KruskalMST();

    system("pause");
    return 0;
}

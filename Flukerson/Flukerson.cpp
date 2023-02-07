#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>

using namespace std;

class FlowNetwork{

private:
    int node_number;
    vector<vector<int>> Matrix;

public:
    FlowNetwork():node_number(0){};
    FlowNetwork(int n):node_number(n){

        Matrix.resize(n);
        for (int i = 0; i < node_number; ++i) {
            Matrix[i].resize(n);
        }

    };

    void AddEdge(int from, int to, int capacity);
    void FordFulkerson(int source, int termination);
    bool BFSfindPath(vector<vector<int>> graphResidual, int *pre, int source, int termination);
    int MinCapacity(vector<vector<int>> graphResidual, int *pre, int termination);

};

void FlowNetwork::AddEdge(int from, int to, int capacity){

    Matrix[from][to] = capacity;

}

void FlowNetwork::FordFulkerson(int source, int termination){

    vector<vector<int>> graphResidual(Matrix); //copy from Matrix
    cout << "Before graphResidual matrix:" << endl;  //print 2-dimension vector
    for (vector<vector<int>>::iterator iter = graphResidual.begin(); iter != graphResidual.end(); ++iter) {
        for (vector<int>::iterator sec = (*iter).begin(); sec != (*iter).end(); ++sec) {
            cout << setw(3) << *sec;
        }
        cout << endl;
    }

    int maxflow = 0;
    int pre[node_number];
    int counter = 0;

    //BFS find augmenting path
    while (BFSfindPath(graphResidual, pre, source, termination)) {
        int minCapacity = MinCapacity(graphResidual, pre, termination);
        maxflow += minCapacity;
        for (int j = termination; j != source; j = pre[j]) {
            int k = pre[j];
            graphResidual[k][j] -= minCapacity;
            graphResidual[j][k] += minCapacity;
        }
        ++counter;
    }
    cout << "Maximum flow:" << maxflow << endl;
    cout << "counter = " << counter << endl;

    cout << "After graphResidual matrix:" << endl;  //print 2-dimension vector
    for (vector<vector<int>>::iterator iter = graphResidual.begin(); iter != graphResidual.end(); ++iter) {
        for (vector<int>::iterator sec = (*iter).begin(); sec != (*iter).end(); ++sec) {
            cout << setw(3) << *sec;
        }
        cout << endl;
    }

}

bool FlowNetwork::BFSfindPath(vector<vector<int>> graphResidual, int *pre, int source, int termination){

    int visited[node_number];

    for (int i = 0; i < node_number; ++i) {
        visited[i] = 0;   //not be found
        pre[i] = -1;
    }

    queue<int> QUEUE;
    QUEUE.push(source);
    visited[source] = 1;
    
    while (!QUEUE.empty()) {
        int exploring = QUEUE.front();
        for (int i = 0; i < node_number; ++i) {
            if (graphResidual[exploring][i] && !visited[i]) {
                QUEUE.push(i);
                visited[i] = 1;
                pre[i] = exploring;
            }
        }
        QUEUE.pop();
    }
    cout << "predecessor:" << endl;
    for (int i = 0; i < node_number; ++i) {
        cout << setw(3) << pre[i];
    }
    cout << endl;
    return (visited[termination] == 1);

}

int FlowNetwork::MinCapacity(vector<vector<int>> graphResidual, int *pre, int termination){

    int Min = 1000;

    for (int i = termination; pre[i] != -1; i = pre[i]) {     //back track, from back to first by predecessor
        if (graphResidual[pre[i]][i] && graphResidual[pre[i]][i] < Min) {
            Min = graphResidual[pre[i]][i];
        }
    }
    return Min;

}

int main(){

    cout << "Ford Fulkerson Algorithm." << endl;

    FlowNetwork g1(6);

    g1.AddEdge(0, 1, 9); g1.AddEdge(0, 3, 9);
    g1.AddEdge(1, 2, 3); g1.AddEdge(1, 3, 8);
    g1.AddEdge(2, 4, 2); g1.AddEdge(2, 5, 9);
    g1.AddEdge(3, 2, 7); g1.AddEdge(3, 4, 7);
    g1.AddEdge(4, 2, 4); g1.AddEdge(4, 5, 8);

    g1.FordFulkerson(0, 5);

    system("pause");
    return 0;
}

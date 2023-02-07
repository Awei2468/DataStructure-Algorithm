#include<bits/stdc++.h>

using namespace std;

int res = INT_MAX, m, n;
int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts);
void dfs(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts, int x, int y, int cost, vector<vector<int>> &trace);

int main() {

    vector<int> startPos = {5,5}, homePos = {5,2};
    vector<int> rowCosts = {7,1,3,3,5,3,22,10,23}, colCosts = {5,5,6,2,0,16};
    cout << minCost(startPos, homePos, rowCosts, colCosts) << endl;

    system("pause");
    return 0;
}

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        m = rowCosts.size(), n = colCosts.size();
        vector<vector<int>> trace(m, vector<int> (n,0));
        dfs(startPos, homePos, rowCosts, colCosts, startPos[0], startPos[1], 0, trace);
        return res;
    }

void dfs(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts, int x, int y, int cost, vector<vector<int>> &trace) {
        if (x < 0 || x >= m || y < 0 || y >= n || trace[x][y]) return;
        if (x == homePos[0] && y == homePos[1]) {
            res = min(res, cost);
            return;
        }
        trace[x][y] = 1;
        dfs(startPos, homePos, rowCosts, colCosts, x+1, y, cost+rowCosts[x+1 >= m ? m-1 : x+1], trace);
        dfs(startPos, homePos, rowCosts, colCosts, x-1, y, cost+rowCosts[x-1 < 0 ? 0 : x-1], trace);
        dfs(startPos, homePos, rowCosts, colCosts, x, y+1, cost+colCosts[y+1 >= n ? n-1 : y+1], trace);
        dfs(startPos, homePos, rowCosts, colCosts, x, y-1, cost+colCosts[y-1 < 0 ? 0 : y-1], trace);
        trace[x][y] = 0;
    }
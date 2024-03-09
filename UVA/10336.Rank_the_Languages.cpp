#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>

using namespace std;
typedef pair<int,char> pr;
int dir[5] = {-1,0,1,0,-1};

void dfs(int i, int j, vector<string> &mp, char c);
void bfs(int i, int j, vector<string> &mp, char c);
void Rank(vector<string> &mp, int res[][26], int wd, bool use_dfs);

int main() {
    int world;
    cout << "How many world:";
    cin >> world;
    cin.get();

    //vector<vector<int>> res;
    //res.resize(world, vector<int>(26,0));
    int res[world][26];
    memset(res, 0, sizeof(res));

    for (int i = 0; i < world; ++i) {
        int h, w;
        cout << "Input Height and Width:";
        cin >> h >> w;
        cin.get();

        vector<string> mp(h);
        for (int j = 0; j < h; ++j) {
            string tmp;
            cin >> tmp;
            cin.get();
            mp[j] = tmp;
        }
        Rank(mp, res, i, true);
    }

    for (int i = 0; i < world; ++i) {
        vector<pr> v;
        for (int j = 0; j < 26; ++j) {
            if (res[i][j]) v.push_back({res[i][j],'a'+j});
        }
        sort(v.begin(), v.end(), [&](pr &p1, pr &p2){
            if (p1.first != p2.first) return p1.first > p2.first;
            else return p1.second < p2.second;
        });
        cout << "World #" << i+1 << "\n";
        for (int j = 0; j < (int)v.size(); ++j) {
            cout << v[j].second << ": " << v[j].first << "\n";
        }
    }

    system("pause");
    return 0;
}

void dfs(int i, int j, vector<string> &mp, char c) {
    if (i < 0 || i >= mp.size() || j < 0 || j >= mp[0].size() || mp[i][j] == '$' || mp[i][j] != c) return;
    mp[i][j] = '$';
    dfs(i+1, j, mp, c);
    dfs(i-1, j, mp, c);
    dfs(i, j+1, mp, c);
    dfs(i, j-1, mp, c);
}

void bfs(int i, int j, vector<string> &mp, char c) {
    queue<pr> q;
    q.push({i,j});
    mp[i][j] = '$';

    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int _x = x+dir[k], _y = y+dir[k+1];
            if (_x >= 0 && _x < mp.size() && _y >= 0 && _y < mp[0].size() && mp[_x][_y] != '$' && mp[_x][_y] == c) {
                q.push({_x,_y});
                mp[_x][_y] = '$';
            }
        }
    }
}

void Rank(vector<string> &mp, int res[][26], int wd, bool use_dfs) {
    for (int i = 0; i < mp.size(); ++i) {
        for (int j = 0; j < mp[0].size(); ++j) {
            if (mp[i][j] != '$') {
                char ori = mp[i][j];
                use_dfs ? dfs(i, j, mp, mp[i][j]) : bfs(i, j, mp, mp[i][j]);               
                res[wd][ori-'a']++;
            }
        }
    }
}


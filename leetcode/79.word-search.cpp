/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool find = false;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (find) return find;
                if (board[i][j] != word[0]) continue;
                dfs(visit, board, word, 0, find, i, j);
            }
        }
        return find;
    }
    void dfs(vector<vector<bool>>& visit, vector<vector<char>>& board, string& word, int idx, bool &find, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visit[i][j] || find || board[i][j] != word[idx]) return;
        if (idx == word.size()-1) {
            find = true;
            return;
        }
        visit[i][j] = true;
        dfs(visit, board, word, idx+1, find, i+1, j);
        dfs(visit, board, word, idx+1, find, i-1, j);
        dfs(visit, board, word, idx+1, find, i, j+1);
        dfs(visit, board, word, idx+1, find, i, j-1);
        visit[i][j] = false;
    }
};
// @lc code=end


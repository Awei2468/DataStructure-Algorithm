/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> ust;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                string s = "$" + to_string(board[i][j]) + "$";
                string row = to_string(i) + s;
                string col = s + to_string(j);
                string block = to_string(i / 3) + s + to_string(j / 3);
                if (ust.count(row) || ust.count(col) || ust.count(block))
                    return false;
                ust.insert(row);
                ust.insert(col);
                ust.insert(block);
            }
        }
        return true;
    }
};
// @lc code=end


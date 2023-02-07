/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> S;
        int res = 0;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "C")
                S.pop();
            else if (ops[i] == "D")
                S.push(S.top()*2);
            else if (ops[i] == "+") {
                int tmp = S.top();
                S.pop();
                int sum = tmp + S.top();
                S.push(tmp);
                S.push(sum);
            }
            else {
                S.push(stoi(ops[i]));
            }
        }
        while (!S.empty()) {
            res += S.top();
            S.pop();
        }
        return res;
    }
};
// @lc code=end


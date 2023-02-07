/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> M;
        int max = INT_MIN;
        for (int i = 0; i < s.size(); ++i) {
            M[s[i]].push_back(i);
        }
        for (auto m : M) {
            if (m.second.size() > 1) {
                sort(m.second.begin(), m.second.end());
                int t = m.second[m.second.size()-1] - m.second[0] - 1;
                if (t > max) max = t;
            }
        }
        return max == INT_MIN ? -1 : max;
    }
};
// @lc code=end


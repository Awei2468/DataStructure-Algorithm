/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, pair<int, int>> M;
        int start = 0, end;
        for (int i = 0; i < s.size(); ++i) {
            if (M.count(s[i])) {
                M[s[i]].second = i;
            }
            else {
                M[s[i]].first = i;
                M[s[i]].second = i;
            }
        }
        while (start < s.size()) {
            end = M[s[start]].second;
            for (int j = start + 1; j <= end; ++j) {
                if (M[s[j]].second > end)
                    end = M[s[j]].second;
            }
            res.push_back(end - start + 1);
            start = end + 1;
        }
        return res;
    }
};
// @lc code=end


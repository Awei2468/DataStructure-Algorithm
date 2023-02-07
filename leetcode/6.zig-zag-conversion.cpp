/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        map <int,string> M;
        int p = 2 * numRows - 2;
        if (!p) return s;
        for (int i = 0; i < s.size(); ++i) {
            int k = i % p;
            if (k <= numRows - 1)
                M[k] += s[i];
            else
                M[p-k] += s[i];
        }
        for (auto m : M) {
            res += m.second;
        }
        return res;
    }
};
// @lc code=end


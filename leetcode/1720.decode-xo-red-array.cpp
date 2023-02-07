/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> res(n+1);
        res[0] = first;
        for (int i = 0, j = 1; i < n; ++i, ++j) {
            res[j] = encoded[i] ^ res[j-1];
        }
        return res;
    }
};
// @lc code=end


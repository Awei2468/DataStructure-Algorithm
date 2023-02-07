/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set <int> S;
            for (int num : nums) {
                S.insert(num & mask);
            }
            int tmp = res | (1 << i);
            for (int member : S) {
                if (S.count(tmp ^ member)) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
        /*  //TLE
        if (nums.size() == 1) return 0;
        int res = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if ((nums[i] ^ nums[j]) > res)
                    res = (nums[i] ^ nums[j]);
            }
        }
        return res;
        */
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (!nums[0]) return "0";
        string res = "";
        for (int &num : nums)
            res += to_string(num);
        return res;    
    }
    static bool cmp(int x, int y) {
        string a = to_string(x) + to_string(y);
        string b = to_string(y) + to_string(x);
        return a > b;
    }
};
// @lc code=end


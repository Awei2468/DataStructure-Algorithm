/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) return nums[nums.size()-1];
        map <int,int> M;
        map <int,int>:: iterator iter;
        int k = 0, res;
        for (int num : nums) {
            M[num]++;
        }
        
        if (M.size() <= 2) {
            iter = M.end();
            --iter;
            res = iter->first;
        }
        else {
            for (iter = M.begin(); iter != M.end(); ++iter) {
                if (k == M.size()-3) {
                    res = iter->first;
                    break;
                }
                ++k;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map <int,int> M;
        for (int num : nums1) {
            ++M[num];
        }
        for (int num : nums2) {
            if (M[num] > 0) {
                M[num] = 0;
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end


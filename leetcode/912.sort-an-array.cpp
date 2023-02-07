/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void QuickSort(vector<int>& nums, int L, int R) {
        if (L >= R) return;
        int k = L-1, pivot = R;
        for (int i = L; i < R; ++i) {
            if (nums[i] < nums[pivot]) {
                ++k;
                swap(nums[i], nums[k]);
            }
        }
        ++k;
        swap(nums[k], nums[pivot]);
        QuickSort(nums, L, k-1);
        QuickSort(nums, k+1, R);
    }
};
// @lc code=end


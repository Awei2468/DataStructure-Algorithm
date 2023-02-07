/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        record = nums;
        record[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            record[i] += record[i-1];
    }
    
    int sumRange(int left, int right) {
        return (left == 0) ? record[right] : record[right]-record[left-1];
    }

private:
    vector<int> record;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end


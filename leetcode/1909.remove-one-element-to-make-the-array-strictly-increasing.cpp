/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

// @lc code=start
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        stack<int> S;
        S.push(nums[0]);
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt > 1) return false;
            if (nums[i] > S.top())
                S.push(nums[i]);
            else {
                if (i == nums.size()-1 && !cnt)
                    break;
                else if (i+1 < nums.size() && nums[i+1] > S.top()) { //bypass self
                    ++cnt;
                }
                else {
                    if (S.top() == nums[i]) return false;
                    S.pop();
                    if (S.empty()) {
                        ++cnt;
                        S.push(nums[i]);
                    }
                    else if (nums[i] > S.top()) { // bypass previous
                        ++cnt;
                        S.push(nums[i]);
                    }
                    else
                        return false;
                }
            }
        }
        return cnt <= 1;
    }
};
// @lc code=end


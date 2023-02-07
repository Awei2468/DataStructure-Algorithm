/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int , int> M;
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i) {
            if (M.count(numbers[i]) == 0) { //if not exist then create
                M[numbers[i]] = i+1;
            }
            if (M.count(target-numbers[i]) && (M[target-numbers[i]] < i+1)) {
                res.push_back(M[target-numbers[i]]);
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */

// @lc code=start
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        /*
        vector<int> res;
        vector<pair<int,bool>> nums_duplicate;
        int sum = 0;
        for (int num : nums) {
            if (abs(num) & 1)
                nums_duplicate.push_back(make_pair(num,false));
            else {
                nums_duplicate.push_back(make_pair(num,true));
                sum += num;
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            int ori = nums_duplicate[queries[i][1]].first;
            nums_duplicate[queries[i][1]].first += queries[i][0];
            int after = nums_duplicate[queries[i][1]].first;
            if (nums_duplicate[queries[i][1]].second && abs(after) & 1) { //even->odd
                nums_duplicate[queries[i][1]].second = false;
                sum -= ori;
            }
            else if (!nums_duplicate[queries[i][1]].second && !(abs(after) & 1)) { //odd->even
                nums_duplicate[queries[i][1]].second = true;
                sum += after;
            }
            else if (nums_duplicate[queries[i][1]].second && !(abs(after) & 1)) { //even->even
                sum += queries[i][0];
            }
            res.push_back(sum);
        }
        return res;
        */
        vector<int> res;
        int sum = 0;
        for (int num : nums) {
            if (!(num & 1))
                sum += num;
        }
        for (int i = 0; i < queries.size(); ++i) {
            int before = nums[queries[i][1]];
            nums[queries[i][1]] += queries[i][0];
            int after = nums[queries[i][1]];
            if ((before & 1) && !(after & 1)) { //odd->even
                sum += after;
            }
            else if (!(before & 1) && (after & 1)) { //even->odd
                sum -= before;
            }
            else if (!(before & 1) && !(after & 1)) { //even->even
                sum += queries[i][0];
            }
            res.push_back(sum);
        }
        return res;
    }
};
// @lc code=end


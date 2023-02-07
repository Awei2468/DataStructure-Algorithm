/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        int idx = CheckType(ruleKey);
        for (int i = 0; i < items.size(); ++i) {
            if (items[i][idx] == ruleValue)
                ++ans;
        }
        return ans;
    }
    int CheckType(string ruleKey) {
        if (ruleKey == "type")
            return 0;
        else if (ruleKey == "color")
            return 1;
        else
            return 2;
    }
};
// @lc code=end


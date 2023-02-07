/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> M;
        for (int num : arr) M[num]++;
        vector<pair<int, bool>> v; //true: <0
        for (auto m : M) {
            if (m.first < 0)
                v.push_back({-m.first, true});
            else
                v.push_back({m.first, false});
        }
        sort(v.begin(), v.end());
        for (auto i : v) {
            if (i.second) { //<0
                int tmp = -i.first;
                if (M[tmp] > M[2 * tmp])
                    return false;
                M[2 * tmp] -= M[tmp];
            }
            else { //>0
                if (M[i.first] > M[2 * i.first])
                    return false;
                M[2 * i.first] -= M[i.first];
            }
        }
        return true;
    }
};
// @lc code=end


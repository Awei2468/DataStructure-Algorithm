/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        map<int, int, greater<int>> M;
        for (vector<int> &v : boxTypes) {
            if (M.count(v[1]))
                M[v[1]] += v[0];
            else
                M[v[1]] = v[0];
        }
        for (auto &m : M) {
            if (m.second <= truckSize) {
                res += (m.first * m.second);
                truckSize -= m.second;
                m.second = 0;
            }
            else {
                while (truckSize > 0 && m.second > 0) {
                    res += m.first;
                    --truckSize;
                    --m.second;
                }
            }
        }
        return res;
    }
};
// @lc code=end


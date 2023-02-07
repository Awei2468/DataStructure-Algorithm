/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
#define two_pair pair<int,int>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res(k);
        priority_queue<two_pair, vector<two_pair>, greater<two_pair>> pq;
        for (int &a : arr) pq.push({abs(a - x), a});
        int i = 0;
        while (i < k) {
            auto it = pq.top();
            pq.pop();
            res[i++] = it.second;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        if (rounds.size() == 1) return {rounds[0]};
        vector<int> res, track(n + 1, 0);
        int len = rounds.size(), max = INT_MIN;
        for (int i = 1; i < len; ++i) {
            int k = rounds[i-1];
            if (rounds[i] > rounds[i-1]) {
                while (k < rounds[i]) {
                    track[k++]++;
                }
            }
            else {
                while (k <= n) {
                    track[k++]++;
                }
                k = 1;
                while (k < rounds[i]) {
                    track[k++]++;
                }
            }
        }
        track[rounds[len-1]]++;
        for (int i = 1; i < n+1; ++i)
            if (track[i] > max) max = track[i];
        for (int i = 1; i < n+1; ++i)
            if (track[i] == max) res.push_back(i);
        return res;
    }
};
// @lc code=end


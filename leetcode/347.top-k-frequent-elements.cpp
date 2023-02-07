/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        vector<int> res;
        unordered_map <int,int> M;
        vector<pair<int,int>> VP;
        for (int n : nums) {
            M[n]++;
        }
        for (auto m : M) {
            VP.push_back({m.first, m.second});
        }
        sort(VP.begin(), VP.end(), cmp);
        for (int i = 0; i < k && i < VP.size(); ++i) {
            res.push_back(VP[i].first);
        } 
        return res;
        */
        unordered_map <int,int> M;
        vector<int> res;
        priority_queue<pair<int,int>> P;  //max heap(according to pair.first)
        for (int num : nums) M[num]++;
        for (auto m : M) P.push({m.second, m.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(P.top().second);
            P.pop();
        }
        return res;
    }
    /*
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    */
};
// @lc code=end


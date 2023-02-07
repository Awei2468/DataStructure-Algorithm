/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        vector<int> res;
        unordered_map <int,int> M;
        for (int i = 0; i < nums2.size(); ++i)
            M[nums2[i]] = i + 1;
        for (int i = 0; i < nums1.size(); ++i) {
            int j = M[nums1[i]] - 1;
            while (++j < nums2.size()) {
                if (nums2[j] > nums1[i]) {
                    res.push_back(nums2[j]);
                    break;
                }
            }
            if (j == nums2.size())
                res.push_back(-1);
        }
        return res;
        */
        
        vector<int> res;
        stack<int> S1;
        unordered_map <int,int> M1;
        for (int num : nums2) {
            while (!S1.empty() && S1.top() < num) {
                M1[S1.top()] = num; 
                S1.pop();
            }
            S1.push(num);
        }   
        for (int num : nums1) {
            if (M1.count(num)) res.push_back(M1[num]);
            else res.push_back(-1);
        }
        return res;
        
    }
};
// @lc code=end


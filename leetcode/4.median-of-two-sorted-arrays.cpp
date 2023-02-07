/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int mid = total >> 1;
        if (nums1.size() && nums2.size()) {
            int i = 0, j = 0;
            stack<int> S;
            while (S.size() <= mid) {
                if (i < nums1.size() && j < nums2.size() && nums1[i] < nums2[j]) {
                    S.push(nums1[i++]);
                }
                else if (i < nums1.size() && j < nums2.size() && nums1[i] > nums2[j]) {
                    S.push(nums2[j++]);
                }
                else if (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
                    S.push(nums1[i++]);
                    S.push(nums2[j++]);
                }
                else {
                    if (i >= nums1.size())
                        S.push(nums2[j++]);
                    else
                        S.push(nums1[i++]);
                }
            }
            if (S.size() - mid > 1) S.pop(); //to avoid add 2 data at the same time and excess mid
            if (total & 1) {  //odd
                return (double)S.top();
            }
            else {
                int t = S.top();
                S.pop();
                return (t + S.top()) / 2.0;
            }
        }
        else if (!nums1.size() && nums2.size()) {
            if (total & 1) {  //odd
                return (double)nums2[mid];
            }
            else {
                return (nums2[mid] + nums2[mid-1]) / 2.0;
            }
        }
        else if (nums1.size() && !nums2.size()) {
            if (total & 1) {  //odd
                return (double)nums1[mid];
            }
            else {
                return (nums1[mid] + nums1[mid-1]) / 2.0;
            }
        }
        else {
            return 0.0;
        }
    }
};
// @lc code=end


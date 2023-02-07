/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Assign(0, nums.size()-1, nums);
    }
    TreeNode* Assign(int L, int R, vector<int>& nums) {
        if (L > R) return NULL;
        int mid = L + ((R-L) >> 1);
        TreeNode *newNode = new TreeNode(nums[mid]);
        newNode->left = Assign(L, mid-1, nums);
        newNode->right = Assign(mid+1, R, nums);
        return newNode;
    }
};
// @lc code=end


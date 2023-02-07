/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int Max = INT_MIN;
        unordered_map <int,int> M;
        LVR(root, M, Max);
        for (auto m : M) {
            if (m.second == Max) res.push_back(m.first);
        }
        return res;
    }
    void LVR(TreeNode *node, unordered_map <int,int> &M, int &max) {
        if (!node) return;
        LVR(node->left, M, max);
        if (max < ++M[node->val]) max = M[node->val];
        LVR(node->right, M, max);
    }
};
// @lc code=end


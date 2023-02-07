/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        unordered_map <int,int> M;
        inorder(root, res);
        for (int i = 0; i < res.size(); ++i) {
            if (M.count(k - res[i]))
                return true;
            else
                M[res[i]] = i;
        }
        return false;
    }
    void inorder(TreeNode* node, vector<int> &tmp) {
        if (!node) return;
        inorder(node->left, tmp);
        tmp.push_back(node->val);
        inorder(node->right, tmp);
    }
};
// @lc code=end


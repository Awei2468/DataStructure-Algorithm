/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> res;
    unordered_set<int> ust;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int &num : to_delete) ust.insert(num);
        TreeNode *t = dfs(root);
        if (t) res.push_back(t);
        return res;
    }
    TreeNode *dfs(TreeNode* root) {
        if (!root) return root;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (ust.find(root->val) != ust.end()) {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            root = nullptr;
        }
        return root;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> Res;
        //preorder(root, Res);
        if (!root) return Res;
        stack<TreeNode*> S;
        S.push(root);

        while (!S.empty()) {
            TreeNode *node = S.top();
            S.pop();
            Res.push_back(node->val);
            if (node->right)
                S.push(node->right);
            if (node->left)
                S.push(node->left);
        }
        return Res;
    }
    /*
    void preorder(TreeNode* root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }
    */
};
// @lc code=end


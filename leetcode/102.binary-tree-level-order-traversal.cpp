/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        vector<int> One_dim;
        queue<TreeNode*> Q;
        Q.push(root);    
        One_dim.push_back(root->val);   
        while (!Q.empty()) {          
            result.push_back(One_dim);
            One_dim.clear();
            for (int i = Q.size(); i > 0; --i) {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left) {
                    Q.push(node->left);
                    One_dim.push_back(node->left->val);
                }
                if (node->right) {
                    Q.push(node->right);
                    One_dim.push_back(node->right->val);
                }
            }
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> Q;
        bool L_R = true;
        Q.push(root);
        while (!Q.empty()) {
            vector<int> single_level;
            for (int i = Q.size(); i > 0; --i) {
                TreeNode *node = Q.front();
                Q.pop();
                single_level.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
            if (L_R)
                L_R = false;
            else {
                L_R = true;
                reverse(single_level.begin(), single_level.end());
            }
            res.push_back(single_level);
        }
        return res;
    }
};
// @lc code=end


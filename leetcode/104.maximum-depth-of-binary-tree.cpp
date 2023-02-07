/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        /*
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
        */
        int result = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            ++result;
            for (int i = Q.size(); i > 0; --i) {
                TreeNode *temp = Q.front();
                Q.pop();
                if (temp->left)
                    Q.push(temp->left);
                if (temp->right)
                    Q.push(temp->right);
            }
        }
        return result;
    }
};
// @lc code=end


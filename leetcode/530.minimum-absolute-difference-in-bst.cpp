/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        inorder(root, ans, pre);
        /*
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            }
            else {
                TreeNode* tmp = s.top();
                s.pop();
                if (pre != -1)
                    ans = min(tmp->val - pre, ans);
                pre = tmp->val;
                node = tmp->right;
            }
        }
        */
        return ans;
    }
    void inorder(TreeNode* node, int &ans, int &pre) {
        if (!node) return;
        inorder(node->left, ans, pre);
        if (pre != -1)
            ans = min(node->val - pre, ans); 
        pre = node->val;
        inorder(node->right, ans, pre);
    }
};
// @lc code=end


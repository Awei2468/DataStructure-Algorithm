/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *ans = NULL;
    bool DFS(TreeNode* n, TreeNode* p, TreeNode* q) {
        if (!n) return false;
        int L = DFS(n->left, p, q) ? 1 : 0;
        int R = DFS(n->right, p, q) ? 1 : 0;
        int M = (n == p || n == q) ? 1 : 0;
        if (L + R + M == 2)
            ans = n;
        return (L + R + M > 0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS(root, p, q);
        return ans;
    }
};
// @lc code=end


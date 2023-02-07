/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int,int> hash;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            hash[inorder[i]] = i;
        }
        return dfs(preorder, 0, n-1, 0);
    }
    TreeNode *dfs(vector<int>& preorder, int s, int e, int t) {
        if (s > e) return nullptr;
        int m = preorder[t], idx = hash[m], leftlen = idx-s-1;
        TreeNode *newNode = new TreeNode(m);
        newNode->left = dfs(preorder, s, idx-1, t+1);
        newNode->right = dfs(preorder, idx+1, e, t+2+leftlen);
        return newNode;
    }
};
// @lc code=end


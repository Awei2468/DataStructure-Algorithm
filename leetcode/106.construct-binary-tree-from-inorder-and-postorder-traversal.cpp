/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            hash[inorder[i]] = i;
        }
        return dfs(postorder, 0, n-1, n-1);
    }
    TreeNode *dfs(vector<int>& postorder, int s, int e, int t) {
        if (s > e) return nullptr;
        int m = postorder[t], idx = hash[m], rightlen = e-idx-1;
        TreeNode *newNode = new TreeNode(m);
        newNode->left = dfs(postorder, s, idx-1, t-2-rightlen); 
        newNode->right = dfs(postorder, idx+1, e, t-1);
        return newNode;
    }
};
// @lc code=end


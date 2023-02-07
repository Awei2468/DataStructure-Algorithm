/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        //DFS
        /*
        if (!root) return 0;
        int height = 1;
        for (Node* sub : root->children) {
            height = max(1 + maxDepth(sub), height);
        }
        return height;
        */
        //BFS
        if (!root) return 0;
        int ans = 0;
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            for (int i = Q.size(); i > 0; --i) {
                Node* tmp = Q.front();
                Q.pop();
                for (Node* sub : tmp->children) {
                    if (sub) Q.push(sub);
                }
            }
            ans++;
        }
        return ans; 
    }
};
// @lc code=end


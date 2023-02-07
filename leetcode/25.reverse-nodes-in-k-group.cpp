/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *subHead = head, *res = head;
        stack<int> S;
        while (CalLength(subHead, S, k) == k) {
            while (!S.empty()) {
                subHead->val = S.top();
                S.pop();
                subHead = subHead->next;
            }
        }
        return res;
    }
    int CalLength(ListNode* node, stack<int> &S1, int k) {
        if (!node) return 0;
        int cnt = 0;
        while (node && k-- > 0) {
            ++cnt;
            S1.push(node->val);
            node = node->next;
        }
        return cnt;
    }
};
// @lc code=end


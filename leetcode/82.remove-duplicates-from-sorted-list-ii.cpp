/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *pre = NULL, *cur = head, *forward = cur->next;
        while (forward) {
            if (cur->val == forward->val) {
                int tmp = cur->val;
                while (cur && cur->val == tmp) {
                    cur = forward;
                    if (forward)
                        forward = forward->next;
                }
                if (pre)
                    pre->next = cur;
                else
                    head = cur;
            }
            else {
                pre = cur;
                cur = forward;
                forward = forward->next;
            }
        }
        return head;
    }
};
// @lc code=end


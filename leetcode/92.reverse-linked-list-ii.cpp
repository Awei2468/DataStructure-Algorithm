/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode *L = nullptr, *R = nullptr, *pre = nullptr, *cur = head, *tail = nullptr;
        int cnt = 1;
        while (cur && cnt != left) {
            pre = cur;
            cur = cur->next;
            ++cnt;
        }
        if (!cur) return head;
        tail = cur;
        while (cnt != right) { //reverse
            ListNode *t = cur->next;
            cur->next = L;
            L = cur;
            cur = t;
            ++cnt;
        }
        R = cur->next;
        cur->next = L;
        if (!pre)
            head = cur;
        else
            pre->next = cur;
        tail->next = R;
        return head;
    }
};
// @lc code=end


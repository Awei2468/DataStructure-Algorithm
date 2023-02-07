/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        if (!head->next || !k) return head;
        ListNode *cur = head, *pre = NULL, *newHead;
        int count = 0;
        while (cur) {
            cur = cur->next;
            ++count;
        }
        if (k % count == 0)
            return head;
        else
            count = count - k % count; //from head to index

        cur = head;
        while (count--) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        newHead = cur;

        while (cur->next) {
            cur = cur->next;    
        }
        cur->next = head;
        return newHead;
    }
};
// @lc code=end


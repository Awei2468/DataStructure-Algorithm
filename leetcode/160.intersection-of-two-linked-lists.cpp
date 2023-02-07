/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int countA = 0, countB = 0, temp;
        ListNode *cur = headA, *cur2, *res;
        while (cur) {
            ++countA;
            cur = cur->next;
        }
        cur = headB;
        while (cur) {
            ++countB;
            cur = cur->next;
        }

        if (countA > countB) {
            temp = countA - countB;
            cur = headA; cur2 = headB;
            while (temp--) {
                cur = cur->next;
            }
        }
        else {
            temp = countB - countA;
            cur2 = headB; cur = headA;
            while (temp--) {
                cur2 = cur2->next;
            }
        }

        while (cur != cur2) {
            cur = cur->next;
            cur2 = cur2->next;
        }
        return (cur && cur2) ? cur : NULL;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> S1, S2, temp;
        ListNode *res, *cur;
        int carry = 0;

        while (l1) {
            S1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            S2.push(l2->val);
            l2 = l2->next;
        }

        while (!S1.empty() && !S2.empty()) {
            if (carry + S1.top() + S2.top() >= 10) {
                temp.push(carry + S1.top() + S2.top() - 10);
                carry = 1;
            }
            else {
                temp.push(carry + S1.top() + S2.top());
                carry = 0;
            }
            S1.pop();
            S2.pop();
        }

        while (!S1.empty()) {
            if (carry + S1.top() >= 10) {
                temp.push(carry + S1.top() - 10);
                carry = 1;
            }
            else {
                temp.push(carry + S1.top());
                carry = 0;
            }
            S1.pop();
        }

        while (!S2.empty()) {
            if (carry + S2.top() >= 10) {
                temp.push(carry + S2.top() - 10);
                carry = 1;
            }
            else {
                temp.push(carry + S2.top());
                carry = 0;
            }
            S2.pop();
        }

        if (carry) {
            temp.push(1);
        }

        ListNode* newNode = new ListNode(temp.top());
        res = newNode;
        cur = res;
        temp.pop();
        while (!temp.empty()) {
            ListNode* newNode = new ListNode(temp.top());
            cur->next = newNode;
            cur = newNode;
            temp.pop();
        }

        return res;
    }
};
// @lc code=end


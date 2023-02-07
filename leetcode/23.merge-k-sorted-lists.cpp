/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (ListNode* sub : lists) {
            while (sub) {
                pq.push(sub->val);
                sub = sub->next;
            }
        }
        if (pq.empty()) return nullptr;

        ListNode *head = new ListNode(pq.top());
        pq.pop();
        ListNode *cur = head;
        while (!pq.empty()) {
            ListNode *t = new ListNode(pq.top());
            pq.pop();
            cur->next = t;
            cur = t;
        }
        return head;
    }
};
// @lc code=end


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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        stack<ListNode*> s;
        while (head) {
            s.push(head);
            head = head->next;
        }
        head = s.top();
        while (!s.empty()) {
            ListNode *p = s.top();
            s.pop();
            p->next = s.empty() ? NULL : s.top();
            p = p->next;
        }
        return head;
    }
};

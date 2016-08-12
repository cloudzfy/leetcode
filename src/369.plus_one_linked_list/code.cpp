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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        while (head) {
            s.push(head);
            head = head->next;
        }
        int carry = 1;
        while (!s.empty()) {
            head = s.top();
            s.pop();
            head->val += carry;
            carry = head->val / 10;
            head->val %= 10;
        }
        if (carry) {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};

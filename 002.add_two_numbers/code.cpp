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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *p = ans;
        while (l1 || l2) {
            int num = carry;
            if (l1) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }
            carry = num / 10;
            p->val = num % 10;
            if (!l1 && !l2) break;
            p->next = new ListNode(0);
            p = p->next;
        }
        if (carry)p->next = new ListNode(carry);
        return ans;
    }
};

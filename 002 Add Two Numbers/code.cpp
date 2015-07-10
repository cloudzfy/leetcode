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
        ListNode* ans = new ListNode(0);
        ListNode* p = ans;
        int carry = 0, v1 = 0, v2 = 0;
        while(l1 != NULL || l2 != NULL)
        {
            v1 = 0;
            v2 = 0;
            if(l1 != NULL)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                v2 = l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode((v1 + v2 + carry) % 10);
            carry = (v1 + v2 + carry) / 10;
            p = p->next;
        }
        if (carry != 0)
        {
            p->next = new ListNode(carry);
            p->next->next = NULL;
        }
        return ans->next;
    }
};
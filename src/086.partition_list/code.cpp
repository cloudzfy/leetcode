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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode* leftHead = new ListNode(0);
        ListNode* rightHead = new ListNode(0);
        ListNode* p = head, *pl = leftHead, *pr = rightHead;
        while(p != NULL) {
            if (p->val < x) {
                pl->next = p;
                pl = pl->next;
                p = p->next;
                pl->next = NULL;
            }
            else {
                pr->next = p;
                pr = pr->next;
                p = p->next;
                pr->next = NULL;
            }
        }
        p = leftHead;
        while(p->next != NULL) p = p->next;
        p->next = rightHead->next;
        return leftHead->next;
    }
};

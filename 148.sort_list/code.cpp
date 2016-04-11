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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *headA = head, *headB = slow->next;
        slow->next = NULL;
        headA = sortList(headA);
        headB = sortList(headB);
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead;
        while (headA && headB) {
            if (headA->val < headB->val) {
                p->next = headA;
                headA = headA->next;
            } else {
                p->next = headB;
                headB = headB->next;
            }
            p = p->next;
        }
        if (headA) p->next = headA;
        if (headB) p->next = headB;
        return newHead->next;
    }
};

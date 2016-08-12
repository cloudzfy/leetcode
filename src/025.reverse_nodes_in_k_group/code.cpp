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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == NULL) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode *tail = head, *pre = newHead;
        while (true) {
            ListNode* p = tail;
            for (int i = 0; i < k; i++) {
                if (!p) return newHead->next;
                p = p->next;
            }
            ListNode *p1 = tail, *p2 = p1->next, *p3 = p2->next;
            for(int i = 0; i < k - 1; i++) {
                p2->next = p1;
                if (i == k - 2) break;
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
            pre->next = p2;
            tail->next = p3;
            pre = tail;
            tail = p3;
        }
        return newHead->next;
    }
};

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode *t1 = newHead, *t2, *p1, *p2, *p3;
        for (int i = 1; i < m; i++) {
            t1 = t1->next;
        }
        p1 = t1->next;
        t2 = p1;
        p2 = p1->next;
        p3 = p2->next;
        for (int i = m; i < n; i++) {
            p2->next = p1;
            if (i < n - 1) {
                p1 = p2;
                p2 = p3;
                p3 = p2->next;
            }
        }
        t2->next = p3;
        t1->next = p2;
        return newHead->next;
    }
};

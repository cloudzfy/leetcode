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
        if (head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = p1->next, *p3 = p2->next;
        while (true) {
            p2->next = p1;
            if (p3 == NULL) break;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        head->next = NULL;
        return p2;
    }
};

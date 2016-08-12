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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode *p1, *p2, *p3;
        p1 = head;
        p2 = head->next;
        if(p2 == NULL) return head;
        p1->next = p1->next->next;
        p2->next = p1;
        head = p2;
        while (p1->next != NULL) {
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next->next->next;
            if(p2 == NULL) break;
            p1->next = p1->next->next;
            p2->next = p1;
            p3->next = p2;
        }
        return head;
    }
};

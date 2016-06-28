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
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = newHead;
        while (pre->next && pre->next->next) {
            ListNode *p1 = pre->next, *p2 = p1->next, *p3 = p2->next;
            pre->next = p2;
            p2->next = p1;
            p1->next = p3;
            pre = pre->next->next;
        }
        return newHead->next;
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead = new ListNode(0);
        ListNode *evenHead = new ListNode(0);
        ListNode *oddTmp = oddHead, *evenTmp = evenHead;
        int choice = 0;
        while (head) {
            if (!choice) {
                oddTmp->next = head;
                head = head->next;
                oddTmp = oddTmp->next;
                oddTmp->next = NULL;
            } else {
                evenTmp->next = head;
                head = head->next;
                evenTmp = evenTmp->next;
                evenTmp->next = NULL;
            }
            choice = (choice + 1) % 2;
        }
        oddTmp->next = evenHead->next;
        return oddHead->next;
    }
};

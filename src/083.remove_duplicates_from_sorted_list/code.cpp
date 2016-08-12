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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = NULL, *cur = head;
        while (cur) {
            if (pre && pre->val == cur->val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

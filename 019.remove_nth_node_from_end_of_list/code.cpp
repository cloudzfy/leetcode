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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre, *post;
        pre = post = head;
        for (int i = 0; i < n; i++) {
            post = post->next;
        }
        if (post == NULL) {
            return head->next;
        }
        while (post->next != NULL) {
            post = post->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

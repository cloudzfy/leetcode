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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * post = head;
        if (head == NULL) return head;
        int count = 0;
        while (post != NULL) {
            post = post->next;
            count++;
        }
        post = head;
        for (int i = 0; i < k % count; i++) {
            post = post->next;
        }
        if (post == NULL) return head;
        ListNode * pre = head;
        while(post->next != NULL) {
            pre = pre->next;
            post = post->next;
        }
        post->next = head;
        head = pre->next;
        pre->next = NULL;
        return head;
    }
};

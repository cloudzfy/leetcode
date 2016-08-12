/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = head;
        int val = 0;
        int len = 1;
        while (p) {
            int num = (double) rand() / RAND_MAX * len;
            if (num == 0) val = p->val;
            p = p->next;
            len++;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

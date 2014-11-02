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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *prev = NULL;
        ListNode *tail = head;
        int move = m - 1;
        while (move--) {
            prev = tail; 
            tail = tail->next;
        }
        int num = n - m;
        ListNode *front = tail;
        while (num-- > 0) {
            ListNode *tmp = tail->next;
            tail->next = tmp->next;
            tmp->next = front;
            front = tmp;
            if(prev)
                prev->next = front;
        }
        return prev ? head : front;
    }
};

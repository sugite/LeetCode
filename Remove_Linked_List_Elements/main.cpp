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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *p2 = new ListNode(-val);
        p2->next = head ;
        ListNode *p3 = p2 , *p1 = head;
        while(p1){
            if(p1->val==val) p2->next = p1->next;
            else p2 = p2->next;
            p1 = p1->next;
        }
        return p3->next;
    }
};
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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL) return head ;
        ListNode *res = head->next ;
        ListNode *p1 = head , *p2 = head->next ;
        while(p1&&p2){
            p1->next = p2->next ;
            p2->next = p1 ;
            ListNode *temp = p1 ;
            p1 = p1->next ;
            if(p1==NULL || p1->next==NULL) return res ;
            p2 = p1->next ;
            temp->next = p2 ;
        }
        return res ;
    }
};

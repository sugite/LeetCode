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
    ListNode *deleteDuplicates(ListNode *head) {
        while(head && head->next && head->val == head->next->val){
            while(head && head->next && head->val == head->next->val){
                head = head->next ;
            }
            head = head->next ;
        }
        if(head==NULL || head->next==NULL) return head ;
        ListNode *p1 = head , *p2 = head ;
        while(p1 && p1->next){
            if(p1->val == p1->next->val){
                int tmp = p1->val ;
                while(p1 && p1->val == tmp){
                    p1 = p1->next ;
                }
                p2->next = p1 ;
                continue ;
            }
            p2 = p1 ;
            p1 = p1->next ; 
        }
        return head ;
    }
};

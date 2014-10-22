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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL && l2==NULL) return NULL ;
        if(l1==NULL) return l2 ;
        if(l2==NULL) return l1 ;
        ListNode *r , *p1 , *p2 ;
        if(l1->val > l2->val){
            r = l2 ;
            p1 = l1 ;
            p2 = l2->next ;
        }else{
            r = l1 ;
            p1 = l1->next ;
            p2 = l2 ;
        }
        ListNode *t = r ; 
        while(p1&&p2){
            if(p1->val > p2->val){
                t->next = p2 ;
                p2 = p2->next ;
            }else{
                t->next = p1 ;
                p1 = p1->next ;
            }
            t = t->next ;
        }
        if(p1==NULL) t->next = p2 ;
        if(p2==NULL) t->next = p1 ;
        return r ;
    }
};

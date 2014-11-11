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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL || n == 0) return head;
        ListNode *p = head , *t = head ;
        while(n--){
            t = t->next;
        }
        if(t==NULL) return head->next;
        while(t->next){
            p = p->next ; 
            t = t->next ;
        }
        p->next = p->next->next ;
        return head;
    }
};

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
    ListNode *rotateRight(ListNode *head, int k) {
        if(k==0 || head == NULL || head->next == NULL) return head ;
        ListNode *p = head ;
        int len = 0 ;
        while(p){
            len++;
            p = p->next;
        }
        if(len<=k) 
            k = k%len;
        if(k==0) return head ;
        p = head ;
        int step = len - k;
        while(--step){
            p = p->next ;
        }
        ListNode *res = p->next;
        ListNode *temp = p->next;
        p->next = NULL;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head ;
        return res;
    }
};

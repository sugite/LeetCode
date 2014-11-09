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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        int last = 0;
        while(l1||l2){
            int a = l1?l1->val:0;
            int b = l2?l2->val:0;
            int c = a+b+last ;
            if(c>9) last = c/10,c%=10;
            else last = 0;
            ListNode *r = new ListNode(c);
            res->next = r;
            res = r ;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(last>0) res->next = new ListNode(last);
        return p->next;
    }
};

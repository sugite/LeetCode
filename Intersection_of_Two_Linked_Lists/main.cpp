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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        int lenA = getLengthOfLinkList(headA);
        int lenB = getLengthOfLinkList(headB);
        if(lenA>=lenB) return func(headA,headB,lenA,lenB);
        return func(headB,headA,lenB,lenA);
    }
    
    ListNode *func(ListNode *headA , ListNode *headB , int lenA , int lenB){
        int diff = lenA-lenB;
        while(diff--) headA = headA->next;
        while(lenB--){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    int getLengthOfLinkList(ListNode *head){
        int len = 0 ;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
};
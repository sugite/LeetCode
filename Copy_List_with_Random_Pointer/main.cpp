/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        RandomListNode *p = head;
        while(p){
            RandomListNode *newNode = new RandomListNode(p->label);
            newNode->next = p->next;
            p->next = newNode ;
            p = newNode->next;
        }
        p = head;
        while(p){
            if(p->random) p->next->random = p->random->next ;
            p = p->next->next ;
        }
        p = head ;
        RandomListNode *newHead = p->next;
        RandomListNode *q = newHead;
        while(p){
            p->next = q->next ;
            p = p->next;
            if(q->next){
                q->next = q->next->next;
                q = q->next;;
            }
        }
        return newHead;
    }
};

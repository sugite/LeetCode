/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
struct CompareNode {
    bool operator()(ListNode* const &node1 , ListNode* const &node2){
        return node1->val > node2->val;
    }
};
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode*>,CompareNode> q;
        for(int i = 0 ; i< lists.size() ; i++){
            if(lists[i])
                q.push(lists[i]);
        }
        ListNode *head  = new ListNode(0);
        ListNode *tail = head;
        while(!q.empty()){
            tail->next = q.top() ;
            tail = tail->next;
            q.pop();
            if(tail->next)
                q.push(tail->next);
        }
        tail->next = NULL;
        return head->next;
    }
};

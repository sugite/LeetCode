#include<iostream>
using namespace std ;

struct ListNode{
	int val ;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public :
	bool hasCycle(ListNode* head){
		if(head==NULL||head->next==NULL) return false;
		ListNode *low = head ;
		ListNode *fast = head->next ;
		while(low!=fast){
			if(fast->next==NULL||fast->next->next==NULL){
				return false;
			}
			low = low->next;
			fast = fast->next->next;
		}
		return true;
	}

};

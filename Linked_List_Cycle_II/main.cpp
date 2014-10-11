#include<iostream>
using namespace std ;

struct ListNode{
	int val ;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public :
	ListNode *detectCycle(ListNode* head){
		if(head==NULL||head->next==NULL) return NULL;
		ListNode *low = head ;
		ListNode *fast = head ;
		do{
			if(fast->next==NULL||fast->next->next==NULL){
				return NULL;
			}
			low = low->next;
			fast = fast->next->next;
		}while(low!=fast);
		low = head ;
		while(low!=fast){
			low = low->next;
			fast= fast->next;
		}
		return low;
	}

};

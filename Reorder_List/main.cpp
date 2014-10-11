#include<iostream>

using namespace std ;

struct ListNode{
	int val;
	ListNode *next ;
	ListNode(int x,ListNode* n)
		:val(x),next(n){}
};

class Solution{
public :
	void reorderList(ListNode *head){
		if(!head||!head->next||!head->next->next)
			return ;
		int len = 0 ;
		ListNode *t = head;
		while(t){
			t = t->next;
			++len;
		}
		int mid = (len-1)/2+1;
		t = head ;
		while(mid--){
			t = t->next;
		}
		t = reverse(t);
		mid = (len-1)/2+1;
		ListNode *h = head;
		while(--mid){
			ListNode *hn = h->next;
			ListNode *tn = t->next;
			t->next = h->next;
			h->next = t;
			t = tn;
			h = hn;
		}
		h->next = t;

	}

	ListNode *reverse(ListNode *head){
		if(head==NULL || head->next ==NULL)
			return head;
		ListNode *a = head ;
		ListNode *b = head->next;
		ListNode *c = head->next->next;
		while(b){
			b->next = a;
			a = b ; 		
			if(c==NULL){
				head->next = NULL ;
				return b;
			}
			b = c;
			c = c->next;
		}
		return NULL;

	}
	
};

int main()
{
	ListNode *node1 = new ListNode(7,NULL);
	ListNode *node2 = new ListNode(6,node1);
	ListNode *node3 = new ListNode(5,node2);
	ListNode *node4 = new ListNode(4,node3);
	ListNode *node5 = new ListNode(3,node4);
	ListNode *node6 = new ListNode(2,node5);
	ListNode *node7 = new ListNode(1,node6);
	Solution sol;
	sol.reorderList(node7);
	while(node7){
		cout<<node7->val;
		node7=node7->next;
	}
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	return 0;
}


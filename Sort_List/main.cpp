#include<iostream>

using namespace std;

struct ListNode{
	int val ; 
	ListNode *next;
	ListNode(int x):val(x),next(0){}
};

class Solution{
public:
	ListNode *SortList(ListNode *head){
		if(!head) return head;
		ListNode *end = head ;
		while(end->next){
			end = end->next;
		}
		quickSort(head,end);
		return head;
	}

	ListNode *partition(ListNode *begin,ListNode *end)
	{
		ListNode*b = begin;
		ListNode * t = b;
		for(ListNode *a = begin->next ; a != end->next ; a = a->next){
			if(a->val<b->val){
				int temp = b->val ;
				b->val = a->val ;
				a->val = temp ;
				t = b ;
				b = b->next;
			}
		}
		return t;

	}

	void quickSort(ListNode *begin,ListNode *end)
	{
		if(begin!=end){
			ListNode *mid = partition(begin,end);
			quickSort(begin,mid);
			quickSort(mid->next,end);
		}	
	}

};

int main(void)
{
	ListNode *head = new ListNode(3);
	ListNode *one1 = new ListNode(1);
	ListNode *one2 = new ListNode(2);
	ListNode *one3 = new ListNode(5);
	ListNode *one4 = new ListNode(9);
	ListNode *one5 = new ListNode(6);
	head->next = one1;
	one1->next = one2;
	one2->next = one3;
	one3->next = one4;
	one4->next = one5;
	Solution sol;
	ListNode *h = sol.SortList(head);
	while(h){
		cout<<h->val<<" ";
		h = h->next;
	}
	delete head;
	delete one1;
	delete one2;
	delete one3;
	delete one4;
	delete one5;
	return 0;
}

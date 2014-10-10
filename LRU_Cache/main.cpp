#include<iostream>
#include<map>

using namespace std;
class Node{
public:
	int k;
	int v;
	Node *prev;
	Node *next;
	Node(int key,int value,Node *p,Node *n)
		:k(key),v(value),prev(p),next(n){}
};


class LRUCache{
private:
	int maxSize ;
	int size ;
	Node *first ;
	Node *last;
	map<int,Node*> cache ;
public:
    LRUCache(int capacity) {
    	maxSize = capacity;
    	size = 0;
    	cache.clear();
	}
	
	int get(int key){
		Node *node = cache[key];
		if(node==0)
			return -1;
		moveToHead(node);
		return node->v;
	}
	
	void moveToHead(Node *node){
		if(node == first)  return;
		if(node == last){
			last = node->prev;
			last->next = NULL;
			node->next = first ;
			first->prev = node;
			first = node;
			return;
		}
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = first ;
		first->prev = node;
		first = node;
	}
	
	void set(int key,int value){
		if(size==0){
			Node *node = new Node(key,value,NULL,NULL);
			first = last = node;
			cache[key] = node;
			size++;
			return;
		}
		
		Node *node = cache[key];
		if(node){
			node->v = value;
			moveToHead(node);
			return;
		}
		node = new Node(key,value,NULL,NULL);
		if(size<maxSize){
			node->next = first;
			first->prev = node;
			first = node;
			cache[key] = node;
			size++;
			return;
		}
		if(size == maxSize){
			if(size==1){
				delete first;
				first=last=NULL;
				size = 0;
				cache.clear();
				set(key,value);				
				return ;
			}
			cache.erase(last->k);
			Node *temp = last;
			last->prev->next = NULL;
			last = last->prev;
			delete temp;
			size--;
			set(key,value);
		}
		
	}
		
};

int main()
{
	LRUCache c(2);
	c.set(2,1);
	c.set(3,2);
	cout<<c.get(3)<<endl;
	cout<<c.get(2)<<endl;
	c.set(4,3);
	cout<<c.get(2)<<endl;
	cout<<c.get(3)<<endl;
	cout<<c.get(4)<<endl;
	return 0;
}

/* 
Delete Middle Node:
Implement an algorithm to delete a node in the middle(i.e. any node but the first and last node, 
not necessarily the exact middle) of a singly linked ist, give only access to that node
EXAMPLE
Input: the node c from the linked list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
*/


#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

struct node{
	int val;
	struct node* next;
	node(int val=0, struct node* next = NULL){
		this->val = val;
		this->next = next;
	}
};
typedef struct node *nodePtr;

void printLinkedList(nodePtr head){
	nodePtr curr = head;
	while(curr){
		cout<<curr->val<<"\t";
		curr = curr->next;
	}
	cout<<"\n\n";
}


nodePtr getLinkedListFromVector(vector<int> arr){
	// prepare linked list
	int n = arr.size();
	nodePtr head = new node(arr[n-1]);
	for(int i = n-2; i >= 0 ; --i)
		head = new node(arr[i], head);
	cout<<"Input linked list: \n";
	printLinkedList(head);
	return head;
}


int main(){
	// get Input linked list
	vector<int> arr = {3,5,6,2,45, 9,23,13};
	nodePtr head = getLinkedListFromVector(arr);
	int nDelete;
	cout<<"Enter node to be deleted"<<endl;
	cin>>nDelete;

	// delete middle node 'nDelete'
	head = new node(0, head);
	nodePtr curr = head->next, prev = head;
	while(curr){
		if( curr->val == nDelete ){
			prev->next = curr->next;
			delete curr;
			break;
		}else{
			prev = curr;
			curr = curr->next;
		}
	}
	cout<<"Linked list with deleted node: \n";
	curr = head->next;
	delete head;
	head = curr;
	printLinkedList(head);


}


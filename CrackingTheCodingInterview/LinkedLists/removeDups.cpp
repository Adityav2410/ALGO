/*
Remove Dups
Write code to remo ve duplicates from an unsorted linkedlist.
FOLLOW UP: How would you solve this problem if a temporary buffer is not allowed.
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

int main(){

	bool debug = false;

	// prepare linked list
	vector<int> arr = {3,5,6,2,45,3, 9,23,6,13, 5, 3};
	int n = arr.size();
	nodePtr head = new node(arr[n-1]);
	for(int i = n-2; i >= 0 ; --i)
		head = new node(arr[i], head);
	cout<<"Input linked list: \n";
	printLinkedList(head);

	// remove duplicates with method of runner
	nodePtr curr = head;
	while( curr ){
		// cout<<"Current : "<<curr->val<<endl;
		nodePtr runner = curr;
		while( runner && runner->next ){
			// cout<<"Checking node: "<<runner->next->val<<endl;
			if(runner->next->val == curr->val){
				nodePtr temp = runner->next;
				runner->next = runner->next->next;
				delete temp;
			}
			runner = runner->next;
		}
		if(debug)
			printLinkedList(head);
		curr = curr->next;
	}
	cout<<"Duplicate removed linked list: \n";
	printLinkedList(head);
}
/* 
Partition
Write code to partition a linked list around a value x, 
such that all nodes less than x come before all nodes greater than or equal to x.
If x is contained within the list, the values of x only need to be after the elements 
less than x. The partition element x  can appear anywhere in the "right partition"; 
it does not need to appear between the left and right partitions. 
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
	vector<int> arr = {3,5,6,2,45,3, 9,23,6,13, 5, 3};
	nodePtr head = getLinkedListFromVector(arr);
	int partitionVal;
	cout<<"Enter value to be partitioned around"<<endl;
	cin>>partitionVal;

	// partiton linked list
	nodePtr curr = head, tail = head;
	while( curr ){
		nodePtr nxt = curr->next;

		if( curr->val < partitionVal ){
			curr->next = head;
			head = curr;
		}else{
			tail->next = curr;
			tail = curr;
		}
		curr = nxt;
	}
	tail->next = NULL;
	cout<<"Partitioned linked list:- "<<endl;
	printLinkedList(head);
}


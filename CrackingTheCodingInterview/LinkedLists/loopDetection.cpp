/*
Loop detection:
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop

DEFINITION
Circular linked list: A(corrupt) linked list in which a node'x next pointer points to an earlier node, so that as to make a loop in the linked list
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>

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

int getLengthOfList(nodePtr curr){
	int len = 0;
	while(curr){
		len++;
		curr = curr->next;
	}
	return len;
}

void buildLoopInList(nodePtr head){
	int len = getLengthOfList(head);
	// loop from last node to 6th node from beginning
	nodePtr circleStartNode = head->next->next->next->next->next->next;
	nodePtr curr = head;
	while(curr && curr->next )
		curr = curr->next;
	curr->next = circleStartNode;
	cout<<"Last node: "<<curr->val<<"\t Loop back to the node: "<<curr->next->val<<endl;
	cout<<"From loop origin node: "<<circleStartNode->val<<"  to the next node: "<<circleStartNode->next->val<<endl;
}

nodePtr detectLoopInList(nodePtr head){
	nodePtr slow = head, fast = head->next;
	while( fast && fast->next){
		if( slow == fast )
			return slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	return NULL;
}

nodePtr getLoopOriginNode(nodePtr head, nodePtr coincideNode){
	nodePtr slow = head;
	nodePtr fast = coincideNode->next;
	int i = 0;
	while( slow != fast ){
		i++;
		cout<<"slow: "<<slow->val<<"\t fast: "<<fast->val<<endl;		
		if(i == 40 )
			break;
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}


int main(){
	// get Input linked list
	// vector<int> arr = {3,5,6,2,45, 9,23,13};
	vector<int> arr = {3,5,6,2, 6, 5, 3, 9, 13, 27, 9, 76};
	nodePtr head = getLinkedListFromVector(arr);
	buildLoopInList(head);
	// check if list is palindrome

	nodePtr coincideNode = detectLoopInList(head);
	if( coincideNode ){
		cout<<"coincide node of runners: "<<coincideNode->val<<endl;
		nodePtr loopOriginNode = getLoopOriginNode(head, coincideNode);
		cout<<"Loop origin node: "<<loopOriginNode->val<<endl;
	}else{
		cout<<"Loop does not exist in list"<<endl;
	}

}


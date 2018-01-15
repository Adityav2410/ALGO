/*
Sum Lists
You have two numbers represented by a linked list, 
where each node contains a single digit. 
Part A
The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
Write function that adds the two numbers and returns the sum as a linked list.

Part B:
Suppose the digits are stored in forward order, Repeat the above problem
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

int getLengthOfList(nodePtr curr){
	int len = 0;
	while(curr){
		len++;
		curr = curr->next;
	}
	return len;
}

nodePtr add2ListUtil(nodePtr head1, nodePtr head2, int &carry){
	if( head1 && head2){
		nodePtr tailNode = add2ListUtil(head1->next, head2->next, carry);
		int currSum = head1->val + head2->val + carry;
		carry = currSum/10;
		nodePtr currNode = new node( currSum%10, tailNode);
		return( currNode );
	}else{
		carry = 0;
		return NULL;
	}
}

nodePtr add2List(nodePtr head1, nodePtr head2 ){
	// equate the length of both lists by appending 0 before shorter list
	int len1 = getLengthOfList(head1), len2 = getLengthOfList(head2);

	int lenDiff = abs(len1-len2);

	nodePtr smaller = len1 < len2 ? head1 : head2;
	nodePtr bigger  = len1 < len2 ? head2 : head1;
	// cout<<"Length 1"<<len1<<endl;
	for(int i=0; i<lenDiff; ++i)
		smaller = new node(0, smaller);
	// cout<<"List1"<<endl;
	// printLinkedList(smaller);
	// cout<<"List2"<<endl;
	// printLinkedList(bigger);

	// add lists by reccursion
	int carry = 0;
	nodePtr sumHead = add2ListUtil(smaller, bigger, carry);
	if( carry )
		sumHead = new node(carry, sumHead);
	return sumHead;
}



int main(){
	// get Input linked list
	vector<int> arr1 = {7,1,6, 8};
	vector<int> arr2 = {5,9,5};
	nodePtr head1 = getLinkedListFromVector(arr1);
	nodePtr head2 = getLinkedListFromVector(arr2);
	nodePtr list1 = head1, list2 = head2;
	// add lists
	nodePtr solnHead = new node();
	nodePtr temp = solnHead;
	int carry = 0;
	
	// part A solution	
	while( head1 || head2 ){
		int sum = (head1?head1->val:0) + (head2?head2->val:0) + carry;
		carry = sum/10;
		sum = sum%10;
		nodePtr curr = new node(sum);
		solnHead->next = curr;
		solnHead = curr;
		head1 = head1?head1->next:head1;
		head2 = head2?head2->next:head2;
	}
	if( carry ){
		nodePtr curr = new node( carry);
		solnHead->next = curr;
	}
	solnHead = temp->next;
	delete temp;
	cout<<"Addition of two numbers( under part A assumption in the form of linked list:- ) "<<endl;
	printLinkedList(solnHead);

	nodePtr partBHead = add2List(list1, list2);
	cout<<"Addition of two numbers( under part B assumption in the form of linked list:- ) "<<endl;
	printLinkedList(partBHead);

}
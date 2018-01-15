/* 
Palindrome
Implement a function to check if a linked list is a palindrome
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

void printContentsOfStack(stack<int> st){
	stack<int> dummy;
	while( !st.empty() ){
		cout<<st.top()<<"\t";
		dummy.push(st.top() );
		st.pop();
	}
	cout<<endl;
	while(!dummy.empty()){
		st.push(dummy.top());
		dummy.pop();
	}
}

bool isLinkedListPalindrome(nodePtr head){
	nodePtr slow = head, fast = head->next;
	stack<int> st;
	st.push(slow->val);
	while( fast && fast->next && fast->next->next ){
		slow = slow->next;
		fast = fast->next->next;
		// cout<<"Fast = "<<fast->val<<endl;
		st.push(slow->val);
	}
	// printContentsOfStack(st);
	if( fast && fast->next ) // odd number of terms in list
		slow = slow->next->next;
	else
		slow = slow->next;
	while( !st.empty() ){
		if( st.top() != slow->val )
			return false;
		else{
			st.pop();
			slow = slow->next;
		}
	}
	return true;
}

int main(){
	// get Input linked list
	// vector<int> arr = {3,5,6,2,45, 9,23,13};
	vector<int> arr = {3,5,6,2, 6, 5, 3, 9};
	nodePtr head = getLinkedListFromVector(arr);
	// check if list is palindrome
	bool palindrome = isLinkedListPalindrome(head);
	if( palindrome )
		cout<<"Linked list is palindrome "<<endl;
	else
		cout<<"Linked list is not palindrome"<<endl;
}


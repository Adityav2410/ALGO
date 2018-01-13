/* 
Return Kth to Last:
Implement an algorithm to find the kth to last element of a single linked list.
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
	int k;
	cout<<"Enter k"<<endl;
	cin>>k;

	// find kth from last 
	// move fast pointer k steps ahead
	nodePtr fast = head;
	int i;
	for( i = 0; fast && i < k ; ++i )
		fast = fast->next;
	if( i < k ){
		cout<<"Fail:\t Less than "<<k<<" values in linked list. Cannot print kth from last element"<<endl;
		return 0;
	}else{
		nodePtr curr = head;
		while( fast ){
			fast = fast->next;
			curr = curr->next;
		}
		cout<<k<<"th element from last in linked list: \t"<<curr->val<<endl;
	}
}
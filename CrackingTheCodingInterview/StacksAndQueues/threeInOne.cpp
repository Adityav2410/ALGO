/*
Three In One:
describe how you could use a single array to implement three stacks
*/

// Below is the implementation for 'k' stacks in an array

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

class kStack{
	private:
		int capacity;
		int nStacks;
		int *top, *free, *next, *data;
		int freeIndex;

	public:
		kStack(int capacity, int nStacks);
		~kStack();
		bool isEmpty(int stackID);
		bool isFull();
		void push(int stackID, int val);
		int pop(int stackID);
		int peek(int stackID);
};

kStack::kStack(int capacity, int nStacks){
	this->capacity  = capacity;
	this->nStacks   = nStacks;
	this->freeIndex = capacity-1;
	top  = new int[nStacks];
	next = new int[capacity];
	free = new int[capacity];
	data = new int[capacity];

	for(int i = 0; i < nStacks; ++i)
		top[i] = -1;
	for(int i = 0; i < capacity; ++i){
		next[i] = -1;
		free[i] = i;
	}
}

kStack::~kStack(){
	delete top;
	delete free;
	delete data;
	delete next;
}

bool kStack::isEmpty(int stackID){
	return(top[stackID] == -1);
}

bool kStack::isFull(){
	return(freeIndex == -1);
}

void kStack::push(int val, int stackID){
	if( isFull() ){
		cout<<"Stack overflow."<<endl;
		return;
	}
	int topIndex = free[freeIndex];
	freeIndex--;
	data[topIndex] = val;
	next[topIndex] = top[stackID];
	top[stackID] = topIndex;
}

int kStack::pop(int stackID){
	if( isEmpty(stackID) ){
		cout<<"Stack underflow"<<endl;
		return -1;
	}
	int retValue = peek(stackID);
	free[++freeIndex] = top[stackID];
	int oldTopIndex = top[stackID];
	top[stackID] = next[top[stackID]];
	next[oldTopIndex] = -1;
	return retValue;
}

int kStack::peek(int stackID){
	if(isEmpty(stackID))
		return -1;
	else
		return data[top[stackID]];
}


int main(){
	int capacity = 10;
	int nStack = 3;
	kStack ks(capacity, nStack);

	ks.pop(2);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    ks.push(29, 2);
    ks.push(83, 2);
    ks.push(16, 1);
    ks.pop(2);
    ks.push(29, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

}//main
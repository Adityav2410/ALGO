/*
Stack of Plates:
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
Threefore in real life, we would likely start a new stack when the rpevious stack exceeds some threshold.
Implement a data struture SetOfStacks that mimics this. SetOfStacks should be composed of
several stacks and should create a new stack once the previous one  exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack,
that is, pop() should return the same values as it would if there were just a single stack.

FOLLOW UP:
Imppelement a function popAt(int index) which performs a pop operation on a specific sub-stack
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<stack>

using namespace std;

class SetOfStacks{
	private:
		int stackCapacity;
		stack<stack<int>> stackStack;
	public:
		SetOfStacks(int stackCapacity);
		void push(int val);
		int pop();
		int peek();
		bool empty();
};

SetOfStacks::SetOfStacks(int stackCapacity){
	this->stackCapacity = stackCapacity;
}

void SetOfStacks::push(int val){
	if( empty() || stackStack.top().size() == stackCapacity ){
		stack<int> newStack;
		newStack.push(val);
		stackStack.push(newStack);
	}else{
		stackStack.top().push(val);
	}
}

int SetOfStacks::pop(){
	if( empty() )
		return(-1);
	else{
		int retValue = stackStack.top().top();
		stackStack.top().pop();
		if(stackStack.top().size() == 0 )
			stackStack.pop();
		return retValue;
	}
}

bool SetOfStacks::empty(){
	return stackStack.empty();
}

int SetOfStacks::peek(){
	if( empty() )
		return(-1);
	else{
		return stackStack.top().top();
	}
}

int main(){
	// This is an incomplete implementation of only PartA, although it has not been tested
	// Part B is not implemented

}
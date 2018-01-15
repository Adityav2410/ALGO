/* 
Stack Min:
How would you design a stack which, in addition to push and pop,
has a function min, which return the minimum element?
Push, pop and min should all operate in O(1) time.
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<stack>
#include<algorithm>

using namespace std;

class MinStack{
	private:
		stack<int> values, minStack;
	public:
		MinStack();
		void push(int val);
		int pop();
		int getMin();
		bool isEmpty();
		int peek();
		int size();
};

MinStack::MinStack(){
	// minStack constructor
	cout<<"Inside constructor"<<endl;
	cout<<"Size of values: "<<values.size()<<endl;
}

void MinStack::push(int val){
	cout<<"Number inserted:\t"<<val<<endl;
	values.push(val);
	if( val <= (minStack.empty()?INT_MAX:minStack.top()) )
		minStack.push(val);
	
}

int MinStack::pop(){
	if( isEmpty() )
		return INT_MAX;
	int retValue = values.top();
	values.pop();
	cout<<"Topmost element removed: "<<retValue<<endl;
	if( retValue == minStack.top() )
		minStack.pop();
	return retValue;
}

int MinStack::getMin(){
	if( minStack.empty() )
		return INT_MAX;
	cout<<"Minimum Element in the stack: "<<minStack.top()<<endl;;
	return minStack.top();

}

int MinStack::peek(){
	if( isEmpty() )
		return -1;
	else
		return values.top();
}

bool MinStack::isEmpty(){
	return values.empty();
}

int MinStack::size(){
	return values.size();
}




int main(){

    MinStack s;
    cout<<"Stack created"<<endl;
    // cout<<"Size of stack: "<<s.size()<<endl;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

}//main
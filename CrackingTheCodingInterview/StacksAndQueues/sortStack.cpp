/*
Sort Stack:
Write a program to sort a stack such that the smallest items are on the top.
You can use an additonal temporary stack, but you may not copy the elements
into any other data structure(such as an array). 
The stack supports the following operations: push, pop, peek and isEmpty.
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>

using namespace std;

class SortStack{
	private:
		stack<int> st, tempSt;
	public:
		void push(int val);
		int pop();
		int peek();
		void shiftFromTemp();
		bool isEmpty();
};


void SortStack::push(int val){
	if( st.size() && st.top() < val ){
		while(st.size() && st.top() < val ){
			tempSt.push(st.top());
			st.pop();
		}
		st.push(val);
	}else if( tempSt.size() && tempSt.top() > val){
		while( tempSt.size() && tempSt.top() > val){
			st.push(tempSt.top());
			tempSt.pop();
		}
		st.push(val);
	}else{
		st.push(val);
	}
}

void SortStack::shiftFromTemp(){
	while( tempSt.size() ){
		st.push(tempSt.top());
		tempSt.pop();
	}
}

int SortStack::peek(){
	shiftFromTemp();
	if( st.size() ){
		return st.top();
	}
	else
		return INT_MAX;
}

int SortStack::pop(){
	shiftFromTemp();
	if( st.size() ){
		int retValue = st.top();
		st.pop();
		return retValue;
	}else{
		return -1;
	}
}

int main(){

	SortStack st;
	st.push(23);
	cout<<"Peeked value: "<<st.peek()<<endl;
	st.push(13);
	cout<<"Peeked value: "<<st.peek()<<endl;
	st.push(18);
	cout<<"Peeked value: "<<st.peek()<<endl;
	st.push(29);
	cout<<"Peeked value: "<<st.peek()<<endl;
	st.push(26);
	cout<<"Popped value: "<<st.pop()<<endl;
	cout<<"Popped value: "<<st.pop()<<endl;
	cout<<"Popped value: "<<st.pop()<<endl;
	cout<<"Popped value: "<<st.pop()<<endl;
	cout<<"Peeked value: "<<st.peek()<<endl;




}
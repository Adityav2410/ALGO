/*
Implement a MyQueue class which implemetns a queue using two stacks
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>

using namespace std;

class Queue{
	private:
		stack<int> s_new, s_old;
	public:
		bool empty();
		void push(int val);
		int pop();
		int front();
		void shiftNewToOld();
		int size();
};

bool Queue::empty(){
	return( s_new.empty() && s_old.empty() );
}

void Queue::push(int val){
	s_new.push(val);
}

int Queue::pop(){
	shiftNewToOld();
	if( s_old.empty() )
		return(-1);
	else{
		int retValue = s_old.top();
		s_old.pop();
		return retValue;
	}
}

void Queue::shiftNewToOld(){
	if( s_old.empty() ){
		while( !s_new.empty() ){
			s_old.push(s_new.top());
			s_new.pop();
		}
	}
}


int Queue::front(){
	shiftNewToOld();
	if( s_old.empty() )
		return -1;
	else
		return s_old.top();
}

int Queue::size(){
	return s_new.size()+s_old.size();
}


int main(){
	Queue q;
	q.push(24);
	q.push(13);
	q.push(21);
	cout<<"Queue front value: "<<q.pop()<<endl;
	q.push(12);
	q.push(18);
	cout<<"Queue front value: "<<q.pop()<<endl;
	cout<<"Queue front value: "<<q.pop()<<endl;
	cout<<"Queue front value: "<<q.pop()<<endl;
	cout<<"Queue size: "<<q.size()<<endl;
}
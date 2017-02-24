#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<queue>

using namespace std;

class Stack
{
	private:
		queue<int> qu;
	public:
		void push(int n);
		void pop();
		int top();
		bool empty();	
		int size();
		void display();
};

void Stack::push(int n)
{
	qu.push(n);
	for(int i=1;i<qu.size();++i)
	{
		qu.push(qu.front());
		qu.pop();
	}
} // Stack::push

void Stack::pop()
{
	if(empty())
		cout<<"No Elements"<<endl;
	else
		qu.pop();

} // Stack::pop

int Stack::top()
{
	if(empty())
	{
		cout<<"Stack Empty"<<endl;
		return(-1);
	}
	return(qu.front());
}

bool Stack::empty()
{
	return( qu.empty());
}

int Stack::size()
{
	return(qu.size());
}

int main()
{
	Stack s;
	s.push(10);	//cout<<s.top()<<s.size()<<"\t"; 
	s.push(5);	//cout<<s.top()<<s.size()<<"\t";
	s.push(7);	//cout<<s.top()<<s.size()<<"\t";
	s.push(13);	//cout<<s.top()<<s.size()<<"\t";
	s.push(19);	//cout<<s.top()<<s.size()<<"\t";
	//cout<<endl;
	cout<<"Stack Size = "<<s.size()<<endl;
	
	while(!s.empty())
	{
		cout<<s.top()<<"\t";
		s.pop();
	}

	cout<<endl;
	s.top();
}
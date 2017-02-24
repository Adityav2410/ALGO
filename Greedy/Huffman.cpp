#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<list>
#include<queue>
#include<vector>

using namespace std;
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

struct node
{	
	char data;
	int frequency;
	bool leaf;
	struct node * left;
	struct node * right;
	node(char data='0', int frequency=0, bool leaf = false, node * left = NULL, node * right = NULL)
	{
		this->data = data;
		this->frequency = frequency ;
		this->leaf = leaf;
		this->left = left;
		this->right = right;
	}
};


struct compareNode
{
	bool operator() (const struct node * n1, const struct  node * n2) const
	{
		return( n2->frequency < n1->frequency);
	}
};


void printPriorQueue(priority_queue<struct node *, vector<struct node *>, compareNode > priorNode)
{
	while(!priorNode.empty())
	{
		node * curr = priorNode.top();	priorNode.pop();
		cout<<"Data"<<curr->data<<"\t Frequency:"<<curr->frequency<<endl;
	}
}

struct node * createHuffmanTree(list<struct node *> nodeList)
{
	priority_queue<struct node * , vector<struct node * >, compareNode > priorNode;
	for(list<struct node *>::iterator it = nodeList.begin(); it!= nodeList.end();++it)
		priorNode.push(*it);

//	printPriorQueue(priorNode);
	struct node * n1;
	struct node * n2;

	while( priorNode.size() > 1)
	{
		 n1 = priorNode.top();		priorNode.pop();
		 n2 = priorNode.top();		priorNode.pop();

		priorNode.push( new struct node('0',n1->frequency+n2->frequency,false,n1,n2)  );
	}

//	node * curr = priorNode.top();
//	cout<<"n1: "<<*n1.data<<n1.frequency<<endl;
//	cout<<"n2: "<<n2.data<<n2.frequency<<endl;
//	cout<<"Top: "<<curr.data<<curr.frequency<<(curr.left)->data<<" "<<(*(curr.right)).data<<endl;

	return( priorNode.top() );
}

void printHuffmanTree( struct node * root)
{
	queue<node *> q;
	q.push(root);

	while(!q.empty())
	{
		node * curr = q.front();
		q.pop();

		if(!curr->leaf)
		{
			cout<<"Node "<<curr->data<<"\t Frequency:"<<curr->frequency<<"\t Children:\tLeft:"<<curr->left->data<<"\tright: "<<curr->right->data<<endl;
			q.push(curr->left);
			q.push(curr->right);
		}
		else
			cout<<"Node: Leaf\t Frequency:"<<curr->frequency<<"\t Data:"<<curr->data<<endl;
	}
	cout<<endl;
}

void generateHuffmanCodes(struct node * root, string prefix)
{
	if(root->leaf)
	{	cout<<root->data<<"   ----------->    "<<prefix<<endl;	return;	}

	generateHuffmanCodes(root->left,prefix+"0");
	generateHuffmanCodes(root->right,prefix+"1");



}//generateHuffmanCode

void createHuffmanCodes(list<node *> nodeList)
{
	struct node * root = createHuffmanTree(nodeList);
	//printHuffmanTree(root);
	generateHuffmanCodes(root,"");


}




int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    list<struct node *> nodeList;
    for(int i=0;i<6;++i)
       	nodeList.push_back( new struct node(arr[i],freq[i],true,NULL,NULL) );

    createHuffmanCodes(nodeList);   
    

}//main
#include<iostream>
#include<map>
using namespace std;


struct node
{
	int data;
	int rank;
	struct node* parent;
};

node* Make_Set(int data,map<int,node*> &m)
{
	node* n = new node();
	n->data = data;
	n->rank = 0;
	n->parent = n;

	m[data] = n;

	return n;
}

node* Find(node *n)
{
	if(n->parent==n)
		return n;
	else
		return n->parent = Find(n->parent);

}

void Union(node* n1,node* n2,std::map<int, node*> &m)
{
    node* pone = Find(n1);
    node* ptwo = Find(n2);
    
    
	int p1 = pone->data;
	int p2 = ptwo->data;

	if(p1==p2)
		return ;
	if(m[p1]->rank>=m[p2]->rank)
	{
		m[p1]->rank = (m[p1]->rank==m[p2]->rank)?m[p1]->rank+1:m[p1]->rank;
		//m[p1]->rank = m[p1]->rank+m[p2]->rank;
		m[p2]->parent = m[p1];
	}
	else
	{
		m[p1]->parent = m[p2];
		//m[p2]->rank = m[p1]->rank+m[p2]->rank;	
	}
}

int main()
{
	std::map<int, node*> m;
	Make_Set(1,m);
	Make_Set(2,m);
	Make_Set(3,m);
	Make_Set(4,m);
	Make_Set(5,m);
	Make_Set(6,m);


	Union(m[1],m[2],m);
	Union(m[2],m[3],m);
	Union(m[3],m[5],m);
	
	node* p = Find(m[4]);

	cout<<p->data<<endl;

}

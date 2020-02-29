#include<iostream>
#include<list>
#include<map>
using namespace std;

struct MinHeapNode
{
	int vertex;
	int distance;
};

class MinHeap
{
	int capacity;
	int size;
	MinHeapNode *minheap;
	map<int , MinHeapNode> map;

	
public:
	void Heapify(int i);
	MinHeap(int c);
	int Capacity();
	int Size();
	//MinHeapNode Create_Node(int v,int d);
	void Heapi();
	void Swap(MinHeapNode &m1,MinHeapNode &m2);
	void Add_Node(int v,int d);
	bool IsThere(int v);
	MinHeapNode Extract_Min();

	bool IsEmpty()
	{
		return this->size;
	}

	void Show();

};


MinHeap :: MinHeap(int c)
	{
		this->capacity = c;
		this->size = 0;
		this->minheap = new MinHeapNode[c];
	}


int MinHeap :: Capacity()
{
	return this->capacity;
}

int MinHeap :: Size()
{
	return this->size;
}




void MinHeap :: Add_Node(int v,int d)
{
	MinHeapNode mm;
	mm.vertex = v;
	mm.distance = d;
	if(size+1<capacity){
		minheap[size] = mm;
		size++;
		map[v] = mm;
	}
	else
		cout<<"Heap if FULL!"<<endl;
}


void MinHeap :: Swap(MinHeapNode &m1,MinHeapNode &m2)
{
	MinHeapNode m = m1;
	m1 = m2;
	m2 = m;
}

MinHeapNode MinHeap :: Extract_Min()
{
	MinHeapNode m = this->minheap[0];

	MinHeapNode m1 = this->minheap[size-1];

	this->minheap[0] = m1;
	this->minheap[size] = m;

	size--;

	map[m.vertex].distance = INT_MIN;

	Heapify(0);

	return m;


}



void MinHeap :: Heapify(int i)
{
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;

	if(l<this->size && this->minheap[l].distance < this->minheap[largest].distance)
		largest = l;

	if(r<this->size && this->minheap[r].distance < this->minheap[largest].distance)
		largest = r;

	if(i!=largest)
	{
		Swap(this->minheap[i],this->minheap[largest]);
		Heapify(largest);
	}

}

void MinHeap :: Heapi()
{
	for(int i=((this->size+1)/2)-1;i>=0;i--)
		Heapify(i);
	//this->Show();
}

void MinHeap:: Show()
{
	for (int i = 0; i < size; i++)
	{
		cout<<this->minheap[i].vertex<<":"<<this->minheap[i].distance<<" ";
	}
	cout<<endl;
}


bool MinHeap:: IsThere(int v)
{
	//cout<<map[v].vertex<<" :"<<map[v].distance<<endl;

	if(map[v].distance == INT_MIN)
		return 0;
	return 1;
} 
int main()
{
	MinHeap m(7);
	m.Add_Node(1,20);
	//m.Show();
	m.Add_Node(2,34);
	//m.Show();
	m.Add_Node(3,4);
	//m.Show();
	m.Add_Node(4,2);
	m.Show();
	m.Heapi();
	m.Show();
	cout<<endl;
		cout<<endl;
	


	MinHeapNode M = m.Extract_Min();
	cout<<M.vertex<<" :"<<M.distance<<endl;

}
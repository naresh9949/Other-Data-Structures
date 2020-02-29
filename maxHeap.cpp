#include<iostream>
#include<list>
#include<map>
using namespace std;

struct MaxHeapNode
{
	int vertex;
	int distance;
};

class MaxHeap
{
	int capacity;
	int size;
	MaxHeapNode *maxheap;
	map<int , MaxHeapNode> map;

	
public:
	void Heapify(int i);
	MaxHeap(int c);
	int Capacity();
	int Size();
	//MinHeapNode Create_Node(int v,int d);
	void Heapi();
	void Swap(MaxHeapNode &m1,MaxHeapNode &m2);
	void Add_Node(int v,int d);
	bool IsThere(int v);
	MaxHeapNode Extract_Max();

	bool IsEmpty()
	{
		return this->size;
	}

	void Show();

};


MaxHeap :: MaxHeap(int c)
	{
		this->capacity = c;
		this->size = 0;
		this->maxheap = new MaxHeapNode[c];
	}


int MaxHeap :: Capacity()
{
	return this->capacity;
}

int MaxHeap :: Size()
{
	return this->size;
}




void MaxHeap :: Add_Node(int v,int d)
{
	MaxHeapNode mm;
	mm.vertex = v;
	mm.distance = d;
	if(size+1<capacity){
		maxheap[size] = mm;
		size++;
		map[v] = mm;
	}
	else
		cout<<"Heap if FULL!"<<endl;
}


void MaxHeap :: Swap(MaxHeapNode &m1,MaxHeapNode &m2)
{
	MaxHeapNode m = m1;
	m1 = m2;
	m2 = m;
}

MaxHeapNode MaxHeap :: Extract_Max()
{
	MaxHeapNode m = this->maxheap[0];

	MaxHeapNode m1 = this->maxheap[size-1];

	this->maxheap[0] = m1;
	this->maxheap[size] = m;

	size--;

	map[m.vertex].distance = INT_MIN;

	Heapify(0);

	return m;


}



void MaxHeap :: Heapify(int i)
{
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;

	if(l<this->size && this->maxheap[l].distance > this->maxheap[largest].distance)
		largest = l;

	if(r<this->size && this->maxheap[r].distance > this->maxheap[largest].distance)
		largest = r;

	if(i!=largest)
	{
		Swap(this->maxheap[i],this->maxheap[largest]);
		Heapify(largest);
	}

}

void MaxHeap :: Heapi()
{
	for(int i=((this->size+1)/2)-1;i>=0;i--)
		Heapify(i);
	//this->Show();
}

void MaxHeap:: Show()
{
	for (int i = 0; i < size; i++)
	{
		cout<<this->maxheap[i].vertex<<":"<<this->maxheap[i].distance<<" ";
	}
	cout<<endl;
}


bool MaxHeap:: IsThere(int v)
{
	//cout<<map[v].vertex<<" :"<<map[v].distance<<endl;

	if(map[v].distance == INT_MIN)
		return 0;
	return 1;
} 
int main()
{
	MaxHeap m(7);
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
	


	MaxHeapNode M = m.Extract_Max();
	cout<<M.vertex<<" :"<<M.distance<<endl;

}
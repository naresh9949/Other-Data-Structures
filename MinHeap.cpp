#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
    int value;
    char name;
};

class MinHeap
{
    int size;
    std::vector<node> minHeap;
    
    public:
    
     MinHeap()
    {
        size = 0;
    }
    
    void Insert(char name,int value)
    {
        node newNode;
        newNode.name = name;
        newNode.value = value;
        
        this->size++;
        
        minHeap.push_back(newNode);
        
        int cur = size-1;
        
        int parent = (cur-1)/2;
        
        while(cur>0)
        {
            if(minHeap[parent].value>minHeap[cur].value)
            {
                swap(minHeap[parent],minHeap[cur]);
                cur = parent;
                parent = (cur-1)/2;
            }
            else
            return;
        }
    }
    
    
    char Extraxt_Min()
    {
        char min = minHeap[0].name;
        
        minHeap[0] = minHeap[size-1];
        
        minHeap.pop_back();
        
        size--;
        
        int cur_pos = 0;
        int left = (2*cur_pos)+1;
        int right = (2*cur_pos)+2;
        
        while(left<size || right<size)
        {
            if(left<size && right<size)
            {
                if(minHeap[left].value<minHeap[right].value && minHeap[left].value<minHeap[cur_pos].value)
                {
                    swap(minHeap[left],minHeap[cur_pos]);
                    
                    cur_pos = left;
                    
                    left = (2*cur_pos)+1;
                    right = (2*cur_pos)+2;
                }
                
                else
                {
                    swap(minHeap[right],minHeap[cur_pos]);
                    
                    cur_pos = right;
                    
                    left = (2*cur_pos)+1;
                    right = (2*cur_pos)+2;
                }
                
            }
            
            else if(left<size && minHeap[left].value<minHeap[cur_pos].value)
            {
                 swap(minHeap[left],minHeap[cur_pos]);
                    
                    cur_pos = left;
                    
                    left = (2*cur_pos)+1;
                    right = (2*cur_pos)+2;
            }
            
            else if(right<size && minHeap[right].value<minHeap[cur_pos].value)
            {
                 swap(minHeap[right],minHeap[cur_pos]);
                    
                    cur_pos = right;
                    
                    left = (2*cur_pos)+1;
                    right = (2*cur_pos)+2;
            }
            
            else
            return min;
            
            
        }
        
        return min;
    }
    
    
    void Show()
    {
        for(int i=0;i<size;i++)
        cout<<"("<<minHeap[i].name<<","<<minHeap[i].value<<")"<<" ";
        cout<<endl;
    }
    
};

int main()
{
    MinHeap m;
    
    m.Insert('A',20);
    m.Insert('b',30);
    m.Insert('c',40);
    m.Insert('d',10);
    m.Insert('f',50);
    //m.Insert('k',2);
    
    m.Show();
    
    cout<<m.Extraxt_Min()<<endl;

    
    
    m.Show();
    
}

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class SQRTDecomposition
{
	int size,b_size;
	int *arr;
	int *blocks;
public:
	SQRTDecomposition(int a[],int n)
	{
		size = n;

		arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = a[i];

		b_size = ceil(sqrt(n));

		blocks = new int[b_size];

		for(int i=0;i<n;i++)
			blocks[i/b_size] += arr[i];

	}

	void show()
	{
		for(int i=0;i<b_size;i++)
			cout<<blocks[i]<<endl;
	}

	void Update(int index,int value)
	{
		int oldvalue = arr[index];

		blocks[index/b_size] += (value-oldvalue);

		arr[index] = value;
	}

	void Query(int l,int r)
	{
		int sum = 0;
		int s_block = (l/b_size);
		int e_block = (r/b_size);

		if(s_block==e_block)
		{
			for(int i=l;i<=r;i++)
				sum+=arr[i];
			cout<<sum<<endl;
			return;
		}

		for(int i=l;i<=(((s_block+1)*b_size)-1);i++)
			sum+=arr[i];

		for(int i=(e_block*b_size);i<=r;i++)
			sum+=arr[i];
	
		for(int i=s_block+1;i<e_block;i++)
			sum+=blocks[i];

		cout<<sum<<endl;
	}
	
	
};

int main()
{
	int n = 8;
	//         0,1,2,3,4,5,6,7
	int a[] = {1,2,6,7,9,3,1,9};

	SQRTDecomposition obj(a,n);
	obj.show();

	obj.Query(2,7);

}
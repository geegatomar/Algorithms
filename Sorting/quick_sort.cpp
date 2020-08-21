#include<bits/stdc++.h>
using namespace std;

int partition(int l, int h, vector<int> &arr)
{
	int pivot = arr[h];
	int pIndex = l, i = l;
	for(i = l; i < h; i++)
	{
		if(arr[i] < pivot)
		{
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[h]);
	return pIndex;
}

void quickSort(int l, int h, vector<int> &arr)
{
	if(l >= h)
		return;
	int j = partition(l, h, arr);
	quickSort(l, j - 1, arr);
	quickSort(j + 1, h, arr);
	
}

int main()
{
	vector<int> arr{9, 4, 6, 8, 2, 3, 1};
	int n = arr.size();
	quickSort(0, n-1, arr);
	for(auto e : arr)
	{
		cout << e << endl;
	}
}


#include<bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, vector<int> &arr)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	
	int l[n1], r[n2];

	for(int i = 0; i < n1; i++)
	       l[i] = arr[low + i];
	for(int i = 0; i < n2; i++)
	       r[i] = arr[mid + 1 + i];
	
	int i = 0, j = 0, k = low;
	while(i < n1 && j < n2)
	{
		if(l[i] <= r[j])
			arr[k++] = l[i++];
		else
			arr[k++] = r[j++];
	}	
	while(i < n1)
	{
		arr[k++] = l[i++];
	}
	while(j < n2)
	{
		arr[k++] = r[j++];
	}

}

void mergeSort(int low, int high, vector<int> &arr)
{
	if(low >= high)
		return;
	int mid = low + (high - low)/2;
	mergeSort(low, mid, arr);
	mergeSort(mid + 1, high, arr);
	merge(low, mid, high, arr);
}

int main()
{
	vector<int> arr{9, 3, 7, 5, 6, 4, 8, 2};
	int i, j, n = arr.size();
	mergeSort(0, n-1, arr);
	for(auto e : arr)
		cout << e << " ";
	cout << endl;
}


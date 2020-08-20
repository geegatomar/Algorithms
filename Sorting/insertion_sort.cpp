#include<bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		for(j = i; j > 0; j--)
		{
			if(arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j-1]);
			}
		}
	}
}

int main()
{
	int arr[] = {7, 8, 1, 4, 3, 9, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


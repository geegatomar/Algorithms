#include<bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		int mini = i;
		for(j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[mini])
				mini = j;
		}
		swap(arr[i], arr[mini]);
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


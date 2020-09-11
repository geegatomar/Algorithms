#include<bits/stdc++.h>
using namespace std;

int calc(int i, int j, int *arr)
{
	if(i >= j)
		return 0;
	int mn = INT_MAX;
	for(int k = i; k < j; k++)
	{
		int temp = calc(i, k, arr) + calc(k + 1, j, arr) 
			+ arr[i-1] * arr[k] * arr[j];
		if(temp < mn)
			mn = temp;
	}
	return mn;
}

int main()
{
	int arr[] = {40, 20, 30, 10, 30};
	int n = sizeof(arr)/sizeof(arr[0]), i, j;
	cout << calc(1, n-1, arr);
}



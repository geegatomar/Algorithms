#include<bits/stdc++.h>
using namespace std;

int calc(int n, int sum, int *arr)
{
	if(sum == 0)
		return 1;
	if(n <= 0 || sum < 0)
		return 0;
	if(arr[n - 1] > sum)
		return calc(n-1, sum, arr);
	else
		return calc(n-1, sum, arr) | calc(n, sum-arr[n-1], arr);
}

int main()
{
	int arr[] = {2, 4, 12, 8, 10};
	int n = sizeof(arr) / sizeof(arr[0]), sum = 11;
	cout << calc(n, sum, arr);
}

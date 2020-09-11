#include<bits/stdc++.h>
using namespace std;

int count(int n, int sum, int *arr)
{
	if(sum == 0)
		return 0;
	if(n <= 0 || sum <= 0)
		return INT_MAX - 1;
	if(sum < arr[n-1])
	       return count(n-1, sum, arr);
	else
	{
		return min(count(n-1, sum, arr), count(n, sum - arr[n-1], arr) + 1);
	}	
}

int main()
{
	int arr[] = {9, 6, 5, 1}, sum = 11, n = 4;
	cout << count(n, sum, arr);
}



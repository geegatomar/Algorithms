#include<bits/stdc++.h>
using namespace std;

int calc(int n, int sum, int *arr)
{
	if(sum == 0)
		return 1;
	if(n <= 0 || sum < 0)
		return 0;
	if(sum < arr[n-1])
		return calc(n-1, sum, arr);
	else
	{
		return calc(n-1, sum, arr) + calc(n, sum - arr[n-1], arr);
	}
}

int main()
{
	int arr[] = {1, 2, 3};
	int n = 3, sum = 4;
	cout << calc(n, sum, arr);
}



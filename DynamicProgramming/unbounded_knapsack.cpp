#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int calc(int n, int w, int *val, int *weight)
{
	if(n <= 0 || w <= 0)
		return 0;
	if(dp[n][w] != -1)
		return dp[n][w];

	if(w < weight[n-1])
		return dp[n][w] = calc(n - 1, w, val, weight);
	else
	{
		return dp[n][w] = max(calc(n-1, w, val, weight), calc(n, w - weight[n-1], val, weight) + val[n-1]); 
	}
}

int main()
{
	int val[] = {10, 40, 50, 70};
	int weight[] = {1, 3, 4, 5};
	int w = 8, n = 4;
	memset(dp, -1, sizeof(dp));
	cout << calc(n, w, val, weight);
}


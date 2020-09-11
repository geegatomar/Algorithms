#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int knapsack(int n, int *val, int* weight, int w)
{
	if(n <= 0 || w <= 0)
		return 0;
	if(dp[n][w] != -1)
		return dp[n][w];
	if(w < weight[n - 1])
	       return dp[n][w] = knapsack(n-1, val, weight, w);
	else
	{
		return dp[n][w] = max(knapsack(n-1, val, weight, w - weight[n-1]) + val[n-1],
				knapsack(n-1, val, weight, w));
	}	
}

int main()
{
	int val[] = {60, 100, 120};
	int weight[] = {10, 20, 30};
	int w = 50;
	int i, j, n = 3;
	memset(dp, -1, sizeof(dp));
	cout << knapsack(n, val, weight, w);
}

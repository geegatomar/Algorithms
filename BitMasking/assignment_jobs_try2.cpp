#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int dp[20][(1 << 20)];

int f(int i, int mask, int &n, vector<vector<int>> &cost)
{
	// we need to assign the ith person a job from the jobs not already assigned
	// if job is already assigned, its represented as 1 in the mask
	if(i < 0)
		return 0;      // all processed

	if(dp[i][mask] != -1)
		return dp[i][mask];

	int mn = INT_MAX;

	for(int j = 0; j < n; j++)
	{
		if(! (mask & (1 << j)) )        // hence jth job is not yet assigned
		{
			mn = min(mn, cost[i][j] + f(i-1, mask|(1 << j), n, cost));
		}
	}
	
	return dp[i][mask] = mn;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, n, k, j, wt, m, knows_zero = 0, a, b, t, sum = 0, mn = 0, val = 0;
	
	cin >> n;
	vector<vector<int>> cost(n, vector<int> (n));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	} 
	memset(dp, -1, sizeof(dp));
	cout << f(n-1, 0, n, cost);
}


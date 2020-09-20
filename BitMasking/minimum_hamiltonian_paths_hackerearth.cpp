#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;

vector<vector<pi>> g;
int dp[21][(1 << 21)];

int dfs(int node, int mask, int n)
{
	
	if(mask == (1 << n) - 1)    // visited all vertices once
	{       
		return 0;
	}
	if(dp[node][mask] != -1)
		return dp[node][mask];

	int mn = 10000000;
	for(auto pr : g[node])
	{
		int v = pr.first, wt = pr.second;
		if(!(mask & (1 << v)))             // if not already been to this vertex, explore it
		{
			mn = min(mn, wt + dfs(v, (mask | (1 << v)), n));
		}
	}
	return dp[node][mask] = mn;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, n, k, j, wt, m, knows_zero = 0, a, b, t, sum = 0, mn = 0, val = 0;
	
	cin >> n >> m;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u-1].push_back({v-1, w});
		g[v-1].push_back({u-1, w});
	}
	int gmn = 10000000;
	memset(dp, -1, sizeof(dp));

	for(i = 0; i < n; i++)
	{
		gmn = min(gmn, dfs(i, 0|(1 << i), n));
	}
	
	cout << gmn;
}


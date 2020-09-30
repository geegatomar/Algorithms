#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int val[20], maxval[20];
int dp[20][2];

int dfs(int node, int prev, int prev_taken)
{
	if(dp[node][prev_taken] != -1)
		return dp[node][prev_taken];

	int mx = 0;
	if(g[node].size() == 1)      // this means its a leaf node (we are writing base case here)
	{
		if(prev_taken)
			return 0;
		return dp[node][prev_taken] = val[node];
	}
	int opt1 = 0, opt2 = (!prev_taken ? val[node] : 0);
	for(auto j : g[node])
	{

		if(j == prev)
			continue;
						         // option 1 :  dont take
		opt1 += dfs(j, node, 0);
		if(!prev_taken)          // if prev not taken, i have option 2 (of taking this node)
		{
			opt2 += dfs(j, node, 1);
		}
	}
	return dp[node][prev_taken] = max(opt1, opt2);
	
}

int main()
{
	int i, j, n, m;
	cin >> n >> m;
	g.resize(n);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(i = 0; i < n; i++)
		cin >> val[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, -1, 0) << endl;
	
}

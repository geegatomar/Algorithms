#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;

int dfs(int node, int prev)
{
	if(g[node].size() == 1 && g[node][0] == prev)         // base case : we have reached leaf node
	{
		return 0;
	}
	int mx = 0;
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		mx = max(mx, dfs(j, node));
	}
	return mx + 1;  
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
	cout << dfs(0, -1) << endl;
}

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int lev[20];

void dfs(int node, int prev)
{
	if(prev != -1)
		lev[node] = lev[prev] + 1;
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		dfs(j, node);
	}
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
	dfs(0, -1);
	int mx = 0, mxind = 0;
	for(i = 0; i < n; i++)
	{
		if(mx < lev[i]) 
		{
			mx = lev[i];
			mxind = i;
		}
		lev[i] = 0;
	}
	
	dfs(mxind, -1);
	mx = 0;
	for(i = 0; i < n; i++)
	{
		mx = max(mx, lev[i]);
	}
	cout << mx << endl;

}

#include<bits/stdc++.h>                // topological sorting is only for DAGs (directed acyclic graphs)
using namespace std;

int n, m;
int vis[100];
vector<vector<int>> g;
vector<int> ans;

void dfs(int node)
{
	if(vis[node])
		return;
	vis[node] = 1;
	for(auto j : g[node])
		dfs(j);
	ans.push_back(node);              // making use of stack in memory
}

void topological_sort()
{
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i);
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	g.resize(n+1);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	topological_sort();
	reverse(ans.begin(), ans.end());
	for(auto e : ans)
		cout << e << " ";
	cout << endl;
}

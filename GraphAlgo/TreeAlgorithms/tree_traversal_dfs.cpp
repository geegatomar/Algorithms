#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

void dfs(int node, int par)
{
	cout << "Node: " << node << " , its parent node: " << par << endl; 
	for(auto j : g[node])
	{
		if(j != par)
			dfs(j, node);
	}
}

int main()
{
	int i, j, n, m, x;
	cin >> n >> m;
	g.resize(n);
	for(i = 0 ; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << "Enter root node to start traversal of tree :  ";
	cin >> x;
	dfs(x, -1);
}



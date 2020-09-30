#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int k;
int subtree_nodes[20];

void dfs(int node, int prev)
{
	//if(g[node].size() == 1 && g[node][0] == prev)
	//	return 1;
	int cnt = 0;

	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		dfs(j, node);
		subtree_nodes[node] += subtree_nodes[j];
	}
	// number of nodes in the subtree of "node" is :
	subtree_nodes[node] += 1;

}

int main()
{
	int i, j, n, m;
	cin >> n >> m >> k;
	g.resize(n);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	int cnt = 0;
	for(i = 0; i < n; i++)
	{
		cout << subtree_nodes[i] << " ";
		if(subtree_nodes[i] <= k)
		       cnt++;	
	}
	cout << endl;
	cout << cnt << endl;
}

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int x, y;

int dfs_lca(int node, int prev)
{
	int numb_diff = 0;
	if(node == x || node == y)
		return node;
	int ret = 0, num;
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		ret = dfs_lca(j, node);
		numb_diff += (ret == -1 ? 0 : 1);
	        if(ret != -1)
			num = ret;
	}
	if(numb_diff == 0)                // both not present, hence return the null -1
		return -1;
	else if(numb_diff == 1)           // they are both on same side of the curr node, so return that
		return num;
	else
		return node;              // else return itself
}

int main()
{
	int i, j, n;
	cin >> n;
	g.resize(n);
	for(i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << "Look for LCA of which two vertices ? " ;
	cin >> x >> y;
	cout << dfs_lca(0, -1) << endl;
}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int counts[10];

void dfs(int node, int prev)
{
	counts[node] = 1;
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		dfs(j, node);
		counts[node] += counts[j];
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
	for(i = 0; i < n; i++)
		cout << counts[i] << " ";
	cout << endl;

}

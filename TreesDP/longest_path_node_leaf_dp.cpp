#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
// IMP: In trees, to keep track of "visitedness", we pass the prev (parent) node in the dfs (IMPORTANT)

int maxHeight[20];

void dfs(int node, int prev)
{
	int mx = 0;
	for(auto j : g[node])
	{
		if(j != prev)          // checking the prev vis condition
		{
			dfs(j, node);
			mx = max(mx, maxHeight[j] + 1);
		}
	}
	maxHeight[node] = mx;
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
	{
		cout << maxHeight[i] << " ";
	}
	cout << endl;
}

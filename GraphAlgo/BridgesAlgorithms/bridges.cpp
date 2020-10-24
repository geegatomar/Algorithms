#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> g;
const int N = 20;
int vis[N], in[N], low[N];
int timer = 0;

void dfs(int node, int par)
{
	vis[node] = 1;
	in[node] = low[node] = timer++;

	for(auto to : g[node])
	{
		if(to == par)
			continue;
		if(vis[to])
		{
			low[node] = min(low[node], in[to]);
		}
		else
		{
			dfs(to, node);
			low[node] = min(low[node], low[to]);
			if(low[to] > in[node])
			{
				cout << "Bridge detected : " << node << " - " << to << endl;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
}

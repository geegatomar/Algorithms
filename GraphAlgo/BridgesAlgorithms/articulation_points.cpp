#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> g;
const int N = 20;
int in[N], low[N], vis[N];
int timer = 1;

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
			// then theres a back edge, and to could be my ancestor
			low[node] = min(low[node], in[to]);
		}
		else
		{
			dfs(to, node);
		
			if(low[to] > in[par] && node != 1)          // root node to be handled separately
			{
				cout << "Articulation point detected : " << node << endl;
			}
			low[node] = min(low[node], low[to]);
		}
	}
	if(node == 1)    // handling root specially
	{
		for(auto ch : g[node])
		{
			if(low[ch] != 1)
			{
				cout << "Articulation point detected : " << node << endl;
				return;
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

#include<bits/stdc++.h>
using namespace std;

int vis[100];
vector<vector<int>> g;

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(auto nbr : g[x])
		{
			if(!vis[nbr])
			{
				vis[nbr] = 1;
				q.push(nbr);
			}
		}
	}
}

int main()
{
	int n, m, i, j;
	cin >> n >> m;      // n vertices and m edges
	g.resize(n);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1);
}

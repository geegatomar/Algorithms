#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, m, SUM = 0;
vector<vector<pair<int, int>>> g;
int vis[20];

void prims(int x)
{
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	for(auto j : g[x])
		pq.push({j.second, j.first});
	vis[x] = 1;
	while(!pq.empty())
	{
		pi p = pq.top();
		pq.pop();
		int wt = p.first, v = p.second;
		if(vis[v])
			continue;
		vis[v] = 1;
		SUM += wt;
		for(auto j : g[v])
		{
			pq.push({j.second, j.first});
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(i = 1; i <= n; i++)
	{
		if(!vis[i])
			prims(i);
	}
	cout << SUM << endl;
}

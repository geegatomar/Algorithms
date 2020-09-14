#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
vector<vector<pi>> g;
int D[10], n, m;

void dijkstras()
{
	for(int i = 0; i < n; i++)
	{
		D[i] = INT_MAX;
	}
	D[0] = 0;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, 0});
	while(!pq.empty())
	{
		pi p = pq.top();
		pq.pop();
		int dist_u = p.first, u = p.second;
		if(dist_u > D[u])
			continue;
		for(pi pr : g[u])
		{
			int v = pr.first, next_dist = pr.second + dist_u;
			if(D[v] > next_dist)
			{
				D[v] = next_dist;
				pq.push({next_dist, v});
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dijkstras();

	for(int i = 0; i < n; i++)
		cout << D[i] << " ";
	cout << endl;
}


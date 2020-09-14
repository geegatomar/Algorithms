#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, m;
vector<vector<pi>> g;
int D[100];             // keeps minimum distance to each node

void dijkstras()
{
	for(int i = 1; i < n; i++)
		D[i] = INT_MAX;
	D[0] = 0;                     // dist to itself is zero;

	priority_queue<pi, vector<pi>, greater<pi>> pq;
	                                                 // pq has pair of (dist, vertex)
	pq.push({0, 0});
	while(!pq.empty())
	{
		pi p = pq.top();
		pq.pop();

		int u = p.second, dist = p.first;
	        if(dist > D[u])                        // this ensures we dont repeat
			continue;
		for(pi pr : g[u])
		{
			int v = pr.first, next_dist = pr.second + dist;
			if(next_dist < D[v])
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

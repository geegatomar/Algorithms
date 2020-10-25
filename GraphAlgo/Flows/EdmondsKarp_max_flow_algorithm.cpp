#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> capacity;       // matrix so store capacity for every pair of vertices
vector<vector<int>> g;              // adjacency list for vertices of graph

int bfs(int s, int t, vector<int> &parent)
{
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, 100000});

	while(!q.empty())
	{
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();

		for(int next : g[cur])
		{
			if(parent[next] == -1 && capacity[cur][next])
			{
				parent[next] = cur;
				int new_flow = min(flow, capacity[cur][next]);
				if(next == t)
					return new_flow;
				q.push({next, new_flow});
			}
		}
	}
	return 0;

}

int maxflow(int s, int t)
{
	int flow = 0;
	vector<int> parent(n + 1);
	int new_flow;

	while(new_flow = bfs(s, t, parent))
	{
		flow += new_flow;
		cout << "New_flow : " << new_flow << endl;		
		// now update the capacity table (for both: residual capacity, and reverse edge residual cap)
		int cur = t;
		while(cur != s)
		{
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;              // residual capacity dec
			capacity[cur][prev] += new_flow;              // reverse edge residual capacity inc
			cur = prev;
		}
	}
	return flow;
}

int main()
{
	cin >> n >> m;
	g.resize(n + 1);
	capacity.resize(n + 1);
	for(i = 0; i <= n; i++)
		capacity[i].resize(m + 1);

	for(i = 0; i < m; i++)
	{
		int u, v, cap;
		cin >> u >> v >> cap;
		g[u].push_back(v);          
		g[v].push_back(u);

		
		capacity[u][v] = cap;
		// Note: We treat it as undirected graph when storing since we can do flow propagation in reverse 			residual edges as well
	}
	cout << "Enter s, t vertices : ";
	int s, t;
	cin >> s >> t;
	cout << maxflow(s, t) << endl;
}

#include<bits/stdc++.h>
using namespace std;

int n, m;
typedef pair<int, int> pi;
vector<vector<pi>> g;
int D[10];

void bellman()
{
	for(int i = 0; i < n; i++)
		D[i] = INT_MAX-100;
	D[0] = 0;

	for(int i = 0; i < n; i++)
	{
		for(int node = 0; node < n; node++)
		{
			for(auto p : g[node])
			{
				int u = p.first, dist = p.second;
				if(D[node] + dist < D[u])
				{
					D[u] = D[node] + dist;
				}
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
	}
	bellman();
	for(int i = 0; i < n; i++)
		cout << D[i] << " ";
	cout << endl;
}


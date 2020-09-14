#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int counts[100];

void dfs(int node, int prev)
{
	if(prev != -1)
		counts[node] = counts[prev] + 1;
	for(auto j : g[node])
	{
		if(prev != j)
			dfs(j, node); 
	}
}

int main()
{
	int n, m, i, j;
	cin >> n >> m;
	g.resize(n+1);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	int mx = 0, ind = 0;
	for(i = 1; i <= n; i++)
	{
		if(counts[i] > mx)
		{
			mx = counts[i];
			ind = i;
		}
	}
	cout << "------------------------- " << endl;
	cout << ind << " " << mx << endl;
	memset(counts, 0, sizeof(counts));
	dfs(ind, -1);
	mx = 0;
	for(i = 1; i <= n; i++)
		mx = max(mx, counts[i]);
	cout << mx << endl;

}


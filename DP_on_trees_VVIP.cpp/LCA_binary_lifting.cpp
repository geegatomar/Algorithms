#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> g;
const int N = 1000, logN = 20;
int lev[N], dp[N + 1][logN + 1];

void dfs(int node, int par)
{
	lev[node] = lev[par] + 1;
	dp[node][0] = par;

	for(int i = 1; i < logN; i++)
	{
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}

	for(auto ch : g[node])
	{
		if(ch == par)
			continue;
		dfs(ch, node);
	}
}

int lca(int u, int v)
{
	if(lev[u] < lev[v])
		swap(u, v);

	int diff = lev[u] - lev[v];
	
	for(int i = 0; i < logN; i++)
	{
		if(diff & (1 << i))
			u = dp[u][i];
	}
	if(u == v)
		return u;

	for(int i = logN - 1; i >= 0; i--)
	{
		if(dp[u][i] != dp[v][i])
		{
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];

}

int main()
{
	cin >> n;
	g.resize(n + 1);
	for(i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	int u, v;
	cout << "Enter u, v : ";
	cin >> u >> v;
	cout << lca(u, v) << endl;

}

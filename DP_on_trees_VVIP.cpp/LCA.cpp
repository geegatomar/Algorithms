#include<bits/stdc++.h>
using namespace std;
int i, n, m, j;
const int N = 1000, logN = 20;
int dp[N][logN], lev[N];
vector<vector<int>> g;

void dfs(int node, int par)
{
	dp[node][0] = par;              // immediate parent
	lev[node] = lev[par] + 1;

	for(i = 1; i < logN; i++)
        {
                dp[node][i] = dp[dp[node][i-1]][i-1];
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
	for(i = 0; i < logN; i++)
	{
		if((1 << i) & diff)
			u = dp[u][i];
	}
	if(u == v)
		return u;
	for(i = logN - 1; i >= 0; i--)
	{
		if(dp[u][i] != dp[v][i])
			u = dp[u][i], v = dp[v][i];
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

	cout << "Enter vertices u and v : ";
	int u, v;
	cin >> u >> v;
	cout << lca(u, v) << endl;
}

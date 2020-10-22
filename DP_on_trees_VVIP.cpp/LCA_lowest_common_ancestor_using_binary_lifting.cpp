#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> g;
const int N = 100, LG = 20;
int lev[N];
int P[N][LG];                          // the 2D array P[][] needs to be of dimension n.logn

void dfs(int node, int par)
{
	lev[node] = lev[par] + 1;
	P[node][0] = par;

	for(int i = 1; i < LG; i++)
        {
                P[node][i] = P[P[node][i-1]][i-1];
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
	for(i = 0; i < LG; i++)
	{
		if(diff & (1 << i))
			u = P[u][i];
	}
	
	if(u == v)
		return u;

	for(int i = LG - 1; i >= 0; i--)
	{
		if(P[u][i] != P[v][i])
		{
			cout << u << " " << v << "  , " << P[u][i] << " " << P[v][i] << endl;
			u = P[u][i];
			v = P[v][i];
		}
	}
	return P[u][0];
}

int main()
{
	cin >> n;
	g.resize(n + 1);
	for(i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	cout << "Enter two vertices to find LCA of : ";
	int u, v;
	cin >> u >> v;
	cout << lca(u, v) << endl;
}

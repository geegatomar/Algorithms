#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> g;
const int N = 100;
int in[N], out[N], num[N];

void dfs1(int node, int par)
{
	in[node] = 0;
	num[node] = 1;

	for(auto child : g[node])
	{
		if(child == par)
			continue;
		dfs1(child, node);

		in[node] += in[child] + num[child];
		num[node] += num[child];
	}
}

void dfs2(int node, int par)
{
	for(auto child : g[node])
	{
		if(child == par)
			continue;
		out[child] = (in[node] - in[child] - num[child]) + out[node] + (n - dp[child]);
	}
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
	dfs1(1, -1);
	dfs2(1, -1);

	for(i = 1; i <= n; i++)
	{
		cout << "Ans for node " << i << " : " << in[i] + out[i] << endl;
	}
}


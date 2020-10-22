#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;
vector<vector<int>> g;
const int N = 100;

// Q. Given a tree, for each node, output the distance of the farthest node from it.

int dp[N], in[N], out[N], ans[N];

// compute in[] array
void dfs1(int node, int prev)
{
	in[node] = 0;
	
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		dfs1(j, node);
		
		in[node] = max(in[node], 1 + in[j]);
	}
	
}

// compute out[] array
void dfs2(int node, int prev)
{
	int mx1 = -1;
	int mx2 = -1;
	
	// first calculate 2 largest in[v]
	for(auto v : g[node])
	{
		if(v == prev)
			continue;
		if(in[v] > mx1)
			mx2 = mx1, mx1 = in[v];
		else if(in[v] > mx2)
			mx2 = in[v];
	}	

	for(auto v : g[node])
	{
		if(v == prev)	continue;
		int use = mx1;
		if(in[v] == mx1)
			use = mx2;
		out[v] = max(1 + out[node], 2 + use);
	        dfs2(v, node);	
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

	dfs1(1, -1);                  // first dfs to find in[] values               
	dfs2(1, -1);	
	for(i = 1; i <= n; i++)
	{
		cout << "Max height of tree when node " << i << " is rooted : ";
	      	cout << max(in[i], out[i]) << endl;	
	}
}

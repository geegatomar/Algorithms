#include<bits/stdc++.h>
using namespace std;
int n, m, k, i, j;
vector<vector<int>> g;
const int N = 100;
int val[N], in[N];

void dfs(int node, int pr)             // pr: parent of node
{
	in[node] = val[node];
	int mx = 0;
	for(auto j : g[node])
	{
		if(j == pr)
			continue;
		dfs(j, node);
		mx = max(mx, in[j]);
	}
	cout << "Node : " << node << " , Max: " << mx << endl;
	in[node] += mx;
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
	for(i = 1; i <= n; i++)
	{
		cin >> val[i];
	}

	dfs(1, -1);
	cout << in[1] << endl;
}


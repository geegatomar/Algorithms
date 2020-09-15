#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g, gr;
int vis[100];
stack<int> st;

void dfs1(int node)
{
	if(vis[node])
		return;
	vis[node] = 1;
	for(auto j : g[node])
		dfs1(j);
	st.push(node);        // add to stack after traversing all its neighbors
}

void dfs2(int node)
{
	if(vis[node])
		return;
	cout << node << " ";
	vis[node] = 1;
	for(auto j : gr[node])         // note: this is where we use the reversed graph(for second dfs)
		dfs2(j);
}

int main()
{
	int i, j;
	cin >> n >> m;
	g.resize(n + 1);
	gr.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		gr[v].push_back(u);        // graph with reversed edges
	}
	// first dfs
	for(i = 1; i <= n; i++)
	{
		dfs1(i);
	}
	memset(vis, 0, sizeof(vis));      // make all unvisited before next dfs
	int cnt = 0;
	while(!st.empty())
	{
		int u = st.top();
		st.pop();
		if(!vis[u])
		{
			cout << "Visiting component : " << ++cnt << endl; 
			dfs2(u);
			cout << endl;
		}
	}
}


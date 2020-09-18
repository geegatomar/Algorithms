#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
int vis[100];
int D[100];

void dfs(int node)
{
	if(vis[node])
		return;
	vis[node] = 1;
	for(auto j : g[node])
	{
		dfs(j);
		D[node] = max(D[node], D[j] + 1);
	}
}	

int main()
{
	int i,j;
	cin >> n >> m;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(i = 1; i <= n; i++)
	{                                   // make directed edge from 0 to every other vertex 
		g[0].push_back(i);
	}
	dfs(0);
	for(i = 0; i <= n; i++)
		cout << D[i] << " ";
	cout << endl << "ANSWER : " << D[0] - 1 << endl;

}


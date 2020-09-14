#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
int vis[100];

void dfs(int node)
{
	if(vis[node])
		return;
	vis[node] = 1;
	cout << node << " ";
	for(auto j : g[node])
		dfs(j);

}

void bfs(int node)
{
	vis[node] = 1;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int x = q.front();
		cout << x << " ";
		q.pop();
		for(auto j : g[x])
		{
			if(!vis[j])
			{
				vis[j] = 1;
				q.push(j);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int i, j;
	g.resize(n);
	for(i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	//dfs(0);
	cout << endl;
	bfs(0);
	cout << endl;
}


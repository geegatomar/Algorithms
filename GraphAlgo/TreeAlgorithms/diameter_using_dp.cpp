#include<bits/stdc++.h>
using namespace std;
                            // toLeaf[x] is the maximum length of path from x to any leaf
			    // maxLength[x] is the max length of path whose highest pt is x
vector<vector<int>> g;
int toLeaf[10], maxLength[10];

void dfs(int node, int prev)
{
	int mx = 0;
	for(auto j : g[node])
	{
		if(prev == j)
			continue;
		dfs(j, node);
		mx = max(mx, toLeaf[j] + 1);
	}	
	toLeaf[node] = mx;
}

void dfs2(int node, int prev)
{
	int mx = 0;
	priority_queue<int> pq;
	for(auto j : g[node])
	{
		if(prev == j)
			continue;
		dfs2(j, node);
		pq.push(toLeaf[j]);
	}
	int n = 2, sum = 0;
	while(!pq.empty() && n)
	{
		sum += pq.top();
		pq.pop();
		n--;
		cout << node << " " << sum << endl;
	}
	maxLength[node] = (2 - n) + sum;
}

int main()
{
	int i, j, n, m;
	cin >> n >> m;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	for(i = 1; i <= n; i++)
		cout << toLeaf[i] << " ";
	cout << endl;
	dfs2(1, -1);
	for(i = 1; i <= n; i++)
		cout << maxLength[i] << " ";
	cout << endl;

}


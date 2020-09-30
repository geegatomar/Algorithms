#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int toLeaf[20];             // toLeaf stores the max length from this node to any leaf (height of node basically)
int maxLength[20];          // maxLength stores the max length with this node as highest node

void dfs(int node, int prev)
{
	int mx = 0;
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		dfs(j, node);
		mx = max(mx, toLeaf[j] + 1);
	}
	toLeaf[node] = mx;
}

void dfs2(int node, int prev)
{
	int mx = 0;                  // we need to extract the max two from its children
	priority_queue<int> pq;
	for(auto j : g[node])
	{
		if(j == prev)
			continue;
		//cout << "Entering neighbor: " << j << "  of " << node <<endl; 
		dfs2(j, node);
		pq.push(toLeaf[j]);
	}
	int n = 2, sum = 0;
        while(!pq.empty() && n)
        {
                sum += pq.top();
                pq.pop();
                n--;
                //cout << node << " " << sum << endl;
        }
        maxLength[node] = (2 - n) + sum;		

}

int main()
{
	int n, m, i, j;
	cin >> n >> m;
	g.resize(n);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	dfs2(0, -1);
	for(i = 0; i < n; i++)
		cout << maxLength[i] << " ";
	cout << endl;

}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int longest(int node, int prev)
{
	int mx = INT_MIN;
	if(g[node].size() == 1 && g[node][0] == prev)          // leaf has degree 1
		return 0;                                      // found leaf
	for(auto j: g[node])
	{
		if(j != prev)
			mx =  max(mx, 1 + longest(j, node));
	}
	return mx;
}

int main()
{
	int i, j, n, m, x;
	cin >> n >> m;
	g.resize(n);
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << "Enter vertex from where you want longest path : ";
	cin >> x;
	cout << longest(x, -1) << endl;
	

}


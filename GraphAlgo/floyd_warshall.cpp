#include<bits/stdc++.h>
using namespace std;

#define inf 1e7
int n, m;
vector<vector<int>> g;

void floyd()
{
	// taking each vertex as intermediate each time
	for(int intr = 0; intr < n; intr++)
	{
		for(int u = 0; u < n; u++)
		{
			for(int v = 0; v < n; v++)
			{
				if(u == intr || v == intr || u == v)
					continue;
				if(g[u][intr] + g[intr][v] < g[u][v])
				{
					g[u][v] = g[u][intr] + g[intr][v];
				}

			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	g.resize(n);
	for(i = 0; i < n; i++)
        {
		g[i].resize(n);
                for(j = 0; j < n; j++)
                {
                        g[i][j] = inf;
                        if(i == j)
                                g[i][j] = 0;
                }
        }

	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;           // this time we are using matrix representation
		                       // unlike usually we used adjacency list representation
	}
	
	floyd();

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << g[i][j] << " ";
		cout << endl;
	}

}


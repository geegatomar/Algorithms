#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
#define inf M-100
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;
vector<vector<pi>> g;
int dist[100];
int sure[100];

void bellman()
{
	int i, j, u, v;
	for(i = 1; i <= n; i++)
	{
		dist[i] = inf;
	}
	dist[1] = 0;
	for(i = 0; i <= n; i++)
	{
		int updated = 0;
		for(u = 1; u <= n; u++)
		{
			if(dist[u] == inf)
				continue;
			for(auto pv : g[u])
			{
				int v = pv.first, w = pv.second;
				if(dist[u] + w < dist[v])
				{
					updated = 1;
					dist[v] = dist[u] + w;
				}
			}
		}
		if(i == n && updated == 1)       // update still happening ==> negative cycle existence
		{
			cout << "-1";
			exit(0);
		}
	}
	for(i = 1; i <= n; i++)
		cout << dist[i] <<  " ";
	cout << endl;
	cout << -dist[n];
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll  sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b, q;
	cin >> n >> m;
	g.resize(n + 1);

	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, -w});
		//g[v].push_back({u, w});
		
	}

	bellman();
	
}

#include<bits/stdc++.h>
using namespace std;

// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

#define int long long
//#define int  long long int 
typedef pair<int, int> pi;
const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf M-100
const int MM = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;
const int hi = 1e18;
const int N = 1e5 + 1;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;
vector<vector<pi>> g;
vector<vector<int>> dist_ij;      // dist between node i and j
vector<int> dist(1002);
int sure[1002];

void djk(int node)
{
	for(int i = 1; i <= n; i++)
	{
		dist[i] = inf;
		sure[i] = 0;
	}
	dist[node] = 0;              // dist of node to itself is zero

	priority_queue<pi, vector<pi>, greater<int>> pq;
	pq.push({0, node});      // {dist, node}
	while(!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();
		int u = curr.second, dist_u = curr.first;
		sure[u] = 1;
		for(auto nbr_u : g[u])
		{
			int v = nbr_u.first, uvw = nbr_u.second;
			if(sure[v])
				continue;
			if(dist[u] + uvw < dist[v])
				dist[v] = dist[u] + uvw;
			pq.push({dist[v], v});
		}
	}
	dist_ij[node] = dist;
}

int32_t main()
{
 

 	ios::sync_with_stdio(false);
  	cin.tie(0);
	int  sal = 0, ii, jj, x, y, l, r;
	int  i, p,mn = INT_MAX, mx = INT_MIN,j, sum = 0, q, t;
	
	cin >> n >> m >> k;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	vector<pi> queries;
	for(i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		queries.push_back({a, b});
	}

	for(i = 1; i <= n; i++)            // running dijkstras for each node ---> O(v . (v + e).logv)
	{
		djk(1);
	}
	// now dist_ij matrix has shortest dist b/w i and j node

	// now iterate over each edge, trying to remove it and calculating shortest for all queries
	 
	for(int u = 1; u <= n; u++)
	{
		for(auto vv : g[u])
		{
			int v = vv.first;
			if(v < u)                 // to avoid repititive counting
				continue;

			// now focussing on edge u-v
			sum = 0;
			
			for(i = 0; i < k; i++)
			{
				int a = queries[i].first, b = queries[i].second;
				// finding min dist b/w nodes a and b considering that u-v edge has been removed
				sum += min({dist_ij[a][b], dist_ij[a][u] + dist_ij[v][b], 
								dist_ij[a][v] + dist_ij[u][b]});
			}

			mn = min(mn, sum);
		}
	}
	cout << mn;
}

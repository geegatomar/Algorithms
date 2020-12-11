#include<bits/stdc++.h>
using namespace std;

// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//#define ll long long
#define int long long

#define all(x)   (x).begin(),(x).end()
//typedef pair<int, int> pi;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
//#define inf M*1000200
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 2e5 + 1;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, w;
vector<vector<pair<int, int>>> g;
int D[10], vis[10];
typedef pair<int, int> pi;

void dijkstras(int start)
{
	for(int i = 0; i < n; i++)
		D[i] = 1000000;
	D[start] = 0;
	vis[start] = 1;

	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, start});

	while(!pq.empty())
	{
		auto curr = pq.top(); pq.pop();
		int node = curr.second, dist_node = curr.first;
		
		for(auto nbpair : g[node])
		{
			int v = nbpair.first, uvw = nbpair.second;
			if(!vis[v] && D[node] + uvw < D[v])
			{
				D[v] = D[node] + uvw;
				pq.push({D[v], v});
			}
		}
	}
}


void bellman_ford(int source)
{
	for(int i = 0; i < n; i++)
		D[i] = 1000000;
	D[source] = 0;

	for(int i = 0; i < n; i++)
	{
		for(int u = 0; u < n; u++)
		{
			for(auto vpair : g[u])
			{
				int v = vpair.first, uvwt = vpair.second;
				if(D[v] > D[u] + uvwt)
					D[v] = D[u] + uvwt;
			}
		}
	}
}

int32_t main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 	ios::sync_with_stdio(false);
  	cin.tie(0);
	int  sal = 0, ii, jj, x, y, l, r;
	int  i, p, j, q, t;
	int mn = INT_MAX, mx = INT_MIN;


	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dijkstras(0);
	for(int i = 0; i < n; i++)
		cout << D[i] << " ";
	cout << endl;
	bellman_ford(0);
	for(int i = 0; i < n; i++)
		cout << D[i] << " ";

}

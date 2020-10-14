#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf M-100
const int lim = 2e5 + 5;
ll n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;
//vector<int> dist[10];        // array of vectors(atmost k: 10)
vector<vector<int>> g;
int vis[lim], par[lim], lev[lim];
ll dp[lim];

void dfs(int node)
{
	if(vis[node] == 1)
		return;
	
	if(node == n)
	{
		dp[node] = 1;
		vis[node] = 2;
		//cou++;
	}
	vis[node] = 1;
	for(auto j : g[node])
	{
		if(!vis[j])
			dfs(j);

		dp[node] += dp[j];
		dp[node] %= M;
	}
	
	vis[node] = 2;
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif

	ll  sal = 0, ii, jj, x, y, ans = 0, l, r;
	ll  i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b, q, d, t;
	cin >> n >> m ;
	g.resize(n + 1);
	
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		
	}
	
	dfs(1);
	cout << dp[1];
	
}

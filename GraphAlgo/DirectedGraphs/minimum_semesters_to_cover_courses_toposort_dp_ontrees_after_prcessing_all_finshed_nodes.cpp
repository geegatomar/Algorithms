#include<bits/stdc++.h>
using namespace std;
 
// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//#define ll long long
#define int long long
int ceil(int a, int b)
{
	return (a + b - 1)/b;
}
#define all(x)   (x).begin(),(x).end()
//typedef pair<int, int> pi;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf 1e15
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9; 
const int N = 2e5 + 2;
int w, h, l, u, r, d;

vector<int> v;
int dp[19000], vis[1000];
vector<vector<int>> g;

void dfs1(int node)
{
	vis[node] = 1;
	for(auto nbr: g[node])
	{
		dfs1(nbr);
	}
	v.push_back(node);
}

void dfs2(int node)
{
	dp[node] = 1000000;
	if(g[node].size() == 0)
		dp[node] = 1;
	
	for(auto nbr : g[node])
	{
		dfs2(nbr);
		dp[node] = min(dp[node], dp[nbr] + 1);
	}
}


void SOLVE()
{
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
			dfs1(i);
	}
	memset(vis, 0, sizeof(vis));
	reverse(v.begin(), v.end());

	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
			dfs2(i);
	}
	for(int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
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
	int  sal = 0, ii, jj,x, y, l, r;
	int  i, j, q;
	int mn = INT_MAX, mx = INT_MIN;
 
 	
	int T = 1;
	//cin >> T;
	for(int I = 1; I <= T; I++)
	{
		//cout << "Case #" << I << ": ";
		SOLVE();
	}
}

#include<bits/stdc++.h>
using namespace std;

// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//#define ll long long
#define int long long
typedef pair<int, int> pi;
const int M = 1e9 + 7;
#define PI 3.14159265358979
const int inf = 1e1;
const int MM = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 5005;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt, sum = 0, d;


vector<vector<pi>> g;
int in[N], num[N], out[N];        //  num[node] stores the number of nodes in its subtree

void dfs(int node, int par)
{
	num[node] = 1;

	for(auto child : g[node])
	{
		int ch = child.first, w = child.second;

		if(ch == par)
			continue;

		dfs(ch, node);
		in[node] += in[ch] + w * num[ch];
		num[node] += num[ch];
	}
}


void dfs2(int node, int par)
{
	for(auto child : g[node])
	{
		int ch = child.first, w = child.second;
		if(ch == par)
			continue;
		int in_siblings = in[node] - in[ch] - (w * (num[ch]));
		cout << "calculating out[" << ch << "] : " << node << " " << out[node] << " " << in_siblings << " " << w << " " << (n - num[ch]) << endl; 
		out[ch] = out[node] + in_siblings + (w * (n - num[ch]));

		dfs2(ch, node);
	}
}


int32_t main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
 	ios::sync_with_stdio(false);
  	cin.tie(0);
	int  sal = 0, ii, jj, x, y, l, r, a, b, c;
	int  i, p, j, q, t;
	int mn = INT_MAX, mx = INT_MIN;

	cin >> n;
	g.resize(n + 1);
	for(i = 0; i < n-1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	} 
	
	dfs(1, 0);
	
	dfs2(1, 0);

	int cnt = 0;
	for(i = 1; i <= n; i++)
	{
		cout << i << " : " << in[i] << " " << out[i] << endl;
		cnt += (in[i] + out[i]);
	}
	cout << cnt << "\n";
}

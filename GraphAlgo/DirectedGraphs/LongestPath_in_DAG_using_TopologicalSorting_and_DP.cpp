#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
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
stack<int> st;

void dfs(int node)
{
	//cout << node << endl;
	if(vis[node])
		return;
	vis[node] = 1;
	for(auto j : g[node])
	{
		if(!vis[j])
			dfs(j);
	}
	st.push(node);
}

vector<int> res;

void topo()
{
	while(!st.empty())
	{
		int u = st.top();
		st.pop();
		for(auto v : g[u])
		{
			
			if(dp[v] >= dp[u] + 1)
			{
				par[v] = u;
				dp[v] = min(dp[v], dp[u] + 1);
			}
		}
	}
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif

	ll  sal = 0, ii, jj, x, y, l, r;
	ll  i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b, q, d, t;
	cin >> n >> m ;
	g.resize(n + 1);
	
	for(i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		
	}
	
	for(i = 1; i <= n; i++)
	{
		dp[i] = 100;
	}
	dp[1] = 0;
	dfs(1);
	//cout << st.size();
	topo();
	
	int snode = n;
	stack<int> ans;
	while(snode != 1)
	{
		
		ans.push(snode);
		snode = par[snode];
	}
	ans.push(1);
	cout << ans.size() << endl;
	while(!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
	
}

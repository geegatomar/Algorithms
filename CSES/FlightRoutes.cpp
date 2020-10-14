#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
#define inf M-100
ll n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;
vector<int> dist[10];        // array of vectors(atmost k: 10)
vector<vector<pi>> g;

void dijkstras()
{
	int i, j;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, 1});

	while(!pq.empty())
	{
		auto pu = pq.top();
		pq.pop();
		int u = pu.second, uw = pu.first;

		if(dist[u].size() >= k)
			continue;

		dist[u].push_back(uw);
		for(auto pv : g[u])
		{
			int v = pv.first, uvw = pv.second;
		
			pq.push({uw + uvw, v});
	
		}
	}

}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif

	ll  sal = 0, ii, jj, x, y, ans = 0, l, r;
	ll  i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b, q, d, t;
	cin >> n >> m >> k;
	g.resize(n + 1);
	
	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		
	}
	
	dijkstras();
	cout << dist[n].size() << endl;
	for(i = 0; i < k; i++)
	{
		cout << dist[n][i] << " ";
	}

}

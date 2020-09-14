#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

int n, m;
vector<vector<pair<int, int>>> g;
int par[100];
int siz[100];
priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

void make_set(int v)
{
	par[v] = v;
	siz[v] = 1;
}

int find_set(int v)
{
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(siz[a] < siz[b])
			swap(a, b);
		siz[a] += siz[b];
		par[b] = a;
	}
}

void kruskals()
{
	while(!pq.empty())
	{
		ppi p = pq.top();
		int w = p.first, u = p.second.first, v = p.second.second;
		pq.pop();
		if(find_set(u) == find_set(v))
			continue;                // if theyre in same set, we just continue
		union_set(u, v);                 // otherwise we union them
		g[u].push_back({v, w});
		g[v].push_back({u, w});

	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	g.resize(n + 1);
	for(i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({w, {u, v}});
	}
	for(i = 0; i <= n; i++)
	{
		make_set(i);
	}
	kruskals();

	cout << "Parent array :   ";
	for(int i = 1; i <= n; i++)
		cout << par[i] << " ";
	cout << endl;

	cout << "Graph : " << endl;
	for(int u = 1; u <= n; u++)
	{
		cout << "For node : " << u << endl;
		for(auto v : g[u])
			cout << v.first << " " << v.second << endl;

	}
	

}


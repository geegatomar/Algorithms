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
vector<vector<int>> v;
vector<vector<int>> D(10, vector<int> (10, 100000));
typedef pair<int, pair<int, int>> ppi;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


bool isvalid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}


void djk(int srcx, int srcy)
{
	D[srcx][srcy] = v[srcx][srcy];
	priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
	pq.push({D[srcx][srcy], {srcx, srcy}});

	while(!pq.empty())
	{
		auto curr = pq.top(); pq.pop();
		int x = curr.second.first, y = curr.second.second;
		for(int i = 0; i < 4; i++)
		{
			int xx = x + dx[i], yy = y + dy[i];
			if(isvalid(xx, yy) && D[xx][yy] > D[x][y] + v[xx][yy])
			{
				D[xx][yy] = D[x][y] + v[xx][yy];
				pq.push({D[xx][yy], {xx, yy}});
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

	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++)
	{
		v[i].resize(n);
		for(int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	m = n;
	djk(0, 0);
	
	cout << D[n - 1][n - 1];
}

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
const int M = 1e8;
#define PI 3.14159265358979
const int inf = 1e12,  inf2 = 1e15;
const int MM = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 1e6 + 5, logN = 20;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt, sum = 0, d;
vector<int> clrs;
vector<vector<int>> p;

int f(int n, int prev_clr_used, int cnt)
{
	if(n < 0)
	{
		if(cnt == k)
			return 0;
		return inf;
	}
	cout << n << " " << prev_clr_used << " " << cnt << endl; 
	int same = 0;
	if(clrs[n] == prev_clr_used || prev_clr_used == -1)
		same = 1;

	if(clrs[n] != 0)    // this tree is already colored
	{
		if(same)
			return f(n - 1, clrs[n], cnt);
		else
			return f(n - 1, clrs[n], cnt + 1);
	}

	int mn = inf;
	for(int j = 0; j < m; j++)
	{
		if(same)
			mn = min(mn, f(n - 1, clrs[n], cnt) + p[n][j]);
		else
			mn = min(mn, f(n - 1, clrs[n], cnt + 1) + p[n][j]);
	}
	return mn;
}

int32_t main()
{
 
 	ios::sync_with_stdio(false);
  	cin.tie(0);
	int  sal = 0, ii, jj, x, y, l, r, a, b, c, g;
	int  i, j, q, t;
	int mn = INT_MAX, mx = INT_MIN;

	cin >> n >> m >> k;
	clrs.resize(n);
	for(i = 0; i < n; i++)
	{
		cin >> clrs[i];
	}

	p.resize(n);
	for(i = 0; i < m; i++)
	{
		p[i].resize(m);
		for(j = 0; j < m; j++)
		{
			cin >> p[i][j];
		}
	}

	cout << f(n - 1, -1, 0) << endl << endl;
}	

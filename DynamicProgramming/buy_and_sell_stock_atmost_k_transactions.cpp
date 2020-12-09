#include<bits/stdc++.h>
using namespace std;

// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//#define ll long long
#define int long long

#define all(x)   (x).begin(),(x).end()
typedef pair<int, int> pi;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
//#define inf M*1000200
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 2e5 + 1;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, w;
vector<int> v;


int solve(int n, int k, vector<int> &v)
{
	if(n < 0 || k <= 0)
		return 0;

	int mx = solve(n - 1, k, v);
	for(int i = n - 1; i >= 0; i--)         // deciding which day i would've bought if im selling now at nth
	{	
		int tmp = solve(i - 1, k - 1, v) + v[n] - v[i];
		mx = max(mx, tmp);
	}
	return mx;

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
		cin >> v[i];
	cin >> k;
	cout << solve(n - 1, k, v);
	
}

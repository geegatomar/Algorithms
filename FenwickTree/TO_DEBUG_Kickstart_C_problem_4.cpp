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
const int M = 1e9;
#define PI 3.14159265358979
#define inf 1e15
//const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9; 
const int N = 2e5 + 2;


// BIT - Binary Indexed Tree
int query(int i, vector<int> &v)
{
	int ans = 0;
	for(; i >= 0; i -= (i & -i))
	{
		ans += v[i];
	}
	return ans;
}

void update(int i, int x, vector<int> &v)
{
	for( ; i < v.size(); i += (i & -i))
	{
		v[i] += x;
	}
}

void build(vector<int> &v, vector<int> &vmultiple, vector<int> &vsingle, int &n)
{
	for(int i = 1; i <= n; i++)
	{
		//vsingle[i] = (i % 2 == 0 ? -v[i] : v[i]);
		//vmultiple[i] = (i % 2 == 0 ? -i*v[i] : i*v[i]);
		if(i % 2 == 0)
		{
			update(i, -v[i], vsingle);
			update(i, -i*v[i], vmultiple);
		}
		else
		{
			update(i, v[i], vsingle);
			update(i, i*v[i], vmultiple);
		}
	}
}
 
void SOLVE()
{
	
	int n, q;
	cin >> n >> q;
	cout << n << " " << q << endl;
	vector<int> v(n + 1, 0), vmultiple(n + 1, 0), vsingle(n + 1, 0);
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
			
	}
	cout << "INPUT DONE\n";
	build(v, vmultiple, vsingle, n);
	cout << "BUILD DONE\n";
	int ans = 0;
	while(q--)
	{
		char ch;
		int l, r;
		cin >> ch >> l >> r;
		if(ch == 'Q')
		{
			int multiple_sum = query(r, vmultiple) - query(l - 1, vmultiple);
			if(l % 2 == 0)
				multiple_sum *= -1;

			int single_sum = query(r, vsingle) - query(l - 1, vsingle);
			if(l % 2 == 0)
				single_sum *= -1;

			ans += multiple_sum - (l - 1) * single_sum;
		}
		else
		{
			int cur = vsingle[l];
			if(l % 2 == 0)
				cur *= -1;
			update(l, -cur, vsingle);
			update(l, -cur*l, vmultiple);

			update(l, r, vsingle);
			update(l, r*l, vmultiple);
		}
	}
	cout << ans << "\n";
	
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
	cin >> T;
	for(int I = 1; I <= T; I++)
	{
		cout << "Case #" << I << ": ";
		SOLVE();
	}
}

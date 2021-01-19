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


int euler(int n)
{
	int ans = n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			ans = ans / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1)
		ans = ans / n * (n - 1);
	return ans;
}


void SOLVE()
{
	int a, m;
	cin >> a >> m;
	int g = __gcd(a, m);
	//cout << g << endl;
	cout << euler(m/g) << "\n";
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
		//cout << "Case #" << I << ": ";
		SOLVE();
	}
}

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
typedef pair<int, int> pi;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
//#define inf M*1000200
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 2e5 + 1;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, w;
vector<int> v;


int power(int x, int n)
{
	if(n == 0)
		return 1;

	int y = power(x, n/2);

	if(n % 2 == 0)
		return y * y;
	else
		return x * y * y;

}

int power_iterative(int x, int n)
{
	int answer = 1;
	while(n)
	{
		if(n % 2 != 0)
			answer = answer * x;
		n /= 2;
		x = x * x;
	}
	return answer;
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


	cin >> x >> n;
	cout << power_iterative(x, n);
}

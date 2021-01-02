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
const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf 1e15
//const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 2e5 + 2;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, w, p;


vector<vector<int>> multiply(vector<vector<int>> m1, vector<vector<int>> m2)
{
	int n = m1.size();
	vector<vector<int>> ans(n, vector<int> (n, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				ans[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return ans;
}

vector<vector<int>> pwr(vector<vector<int>> matrix, int n)
{
	if(n == 1)
		return matrix;
	
	vector<vector<int>> tmp = pwr(matrix, n / 2);

	if(n % 2 == 0)
		return multiply(tmp, tmp);
	else
		return multiply(matrix, multiply(tmp, tmp));
}

void SOLVE()
{
	int n;
	cin >> n;
	vector<vector<int>> matrix(2, vector<int> (2, 0));
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;

	vector<vector<int>> res = pwr(matrix, n);

	cout << res[0][0] * 1 + res[0][1] * 1;
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
	//cin >> T;
	while(T--)
	{
		SOLVE();
	}
}

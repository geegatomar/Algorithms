#include<bits/stdc++.h>
using namespace std;
#define ll  long long int

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, i, j;
	cin >> n;

	// now trying bottom up;
	vector<vector<int>> dp(3, vector<int> (n+1, 0));
	for(i = 0; i < 3; i++)
		dp[i][0] = max({v[0][0], v[1][0], v[2][0]});
	
	for(j = 1; j < n; j++)
	{
		for(i = 0; i < 3; i++)	
		{
			dp[i][j] = max( dp[(i+1)%3][j-1] + v[(i+1)%3][j], dp[(i+2)%3][j-1] + v[(i+2)%3][j]);
		}
	}

	for(auto e: dp)
	{
		for(auto ee: e)
			cout << ee <<" ";
		cout << endl;
	}
	cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]});

}


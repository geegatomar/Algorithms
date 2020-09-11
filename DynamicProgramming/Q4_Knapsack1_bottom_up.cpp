#include<bits/stdc++.h>
using namespace std;
#define ll  long long int

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, i, j, wt;
	cin >> n >> wt;
	vector<int> w(n), v(n);
	for(i = 0; i < n; i++)
		cin >> w[i] >> v[i];

	vector<vector<int>> dp(n + 1, vector<int> (wt + 1, 0));
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= wt; j++)
		{
			if(j - w[i-1] >= 0)
				dp[i][j] = max(dp[i-1][j - w[i-1]] + v[i-1], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][wt];

}

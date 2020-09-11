#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int main()
{
	string x = "abbbchgdfs", y = "aebcdets";
	int n = x.size(), m = y.size(), i, j;
	memset(dp, 0, sizeof(dp));
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(x[i] == y[j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m];

}


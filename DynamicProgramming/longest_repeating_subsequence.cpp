#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x = "aabebcdd";
	int n = x.size(), i, j;
	int dp[100][100] = {0};

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(x[i-1] == x[j-1] && i != j)
				dp[i][j] = 1 + dp[i-1][j-1];
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[n][n] << endl;
}



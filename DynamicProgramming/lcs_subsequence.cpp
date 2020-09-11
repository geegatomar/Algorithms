#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int calc(int n, int m, string x, string y)
{
	if(n <= 0 || m <= 0)
		return 0;
	if(dp[n][m] != -1)
	{	
		return dp[n][m];
	}
	if(x[n-1] == y[m-1])
		return dp[n][m] = 1 + calc(n-1, m-1, x, y);
	else
	{
		return dp[n][m] = max(calc(n-1, m, x, y), calc(n, m-1, x, y));
	}
}

int main()
{
	string x = "abcddgh", y = "abedhhr";
	int n = x.size(), m = y.size();
	memset(dp, -1, sizeof(dp));
	cout << calc(n, m, x, y);
}



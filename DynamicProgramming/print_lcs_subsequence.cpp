#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x = "acbccfgh", y = "abcdafffhg";
	int n = x.size(), m = y.size(), i, j;
	int dp[100][100] = {0};

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(x[i-1] == y[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string s = "";

	for(i = n; i > 0; )
	{
		for(j = m; j > 0; )
		{
			if(x[i-1] == y[j-1])
			{
				s += x[i-1];
				i--;
				j--;
			}
			else
			{
				if(dp[i-1][j] > dp[i][j-1])
				{
					i--;
				}
				else
					j--;
			}
		}
	}
	cout << s << endl;

}


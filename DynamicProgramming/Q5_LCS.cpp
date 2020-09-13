#include<bits/stdc++.h>
using namespace std;
#define ll  long long int

int f(string s1, int n, string s2, int m)
{
	if(n < 0 || m < 0)
		return 0;
	if(s1[n] == s2[m])
		return 1 + f(s1, n-1, s2, m-1);
	else
		return max(f(s1, n-1, s2, m), f(s1, n, s2, m-1));
}

int main()
{
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	int n, i, j, wt, m;
	string s1, s2;
	cin >> s1 >> s2;
	n = s1.size();  m = s2.size();
	//cout << f(s1, n-1, s2, m-1);

	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	cout << dp[n][m] << endl;
	string str = "";

	i = n; j = m;
	while(i >= 0 && j >= 0 && dp[i][j] > 0)
	{
			if(s1[i-1] == s2[j-1])
			{
				str = s1[i-1] + str;
				i--;
				j--;
			}
			else
			{
				if(dp[i-1][j] > dp[i][j-1])
					i--;
				else
					j--;
			}
	}
	cout << str;
	
}


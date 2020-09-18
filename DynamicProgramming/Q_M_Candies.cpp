#define ll long long int 
int n, k;
const int M = 1e9 + 7;
int dp[102][100004];

int f(int n, int k, vector<int> &v)
{
	if(k < 0)
		return 0;
	if(n == 0)
	{
		if(k == 0)
			return dp[n][k] = 1;
		else
			return dp[n][k] = 0;
	}
	if(dp[n][k] != -1)
		return dp[n][k];

	int sum = 0;
	for(int i = 0; i <= v[n-1]; i++)
	{ 
		if(k >= i)
		{
			if(dp[n-1][k-i] == -1)
				dp[n-1][k-i] = f(n-1, k-i, v);
			sum += dp[n-1][k-i];
		}
		sum %= M;
	}
	return dp[n][k] = sum % M;

}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, j, wt, m;
	
	cin >> n >> k;
	vector<int> v(n);
	for(i = 0; i < n; i++)
		cin >> v[i];
	memset(dp, -1, sizeof(dp));

	cout << f(n, k, v);
}


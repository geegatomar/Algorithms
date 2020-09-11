#include<bits/stdc++.h>
using namespace std;

int f(int n, int k, vector<int> &v)
{
	if(n <= 0)
		return 0;
	int mn = INT_MAX;
	for(int i = 1; i <= k; i++)
	{
		if(n-i >= 0)
			mn = min(mn, f(n-i, k, v) + abs(v[n]-v[n-i]));
	}
	return mn;
}

int main()
{
	int n = 5, k = 3;
	vector<int> v{10, 30, 40, 50, 20};
	cout << f(n-1, k, v);
}


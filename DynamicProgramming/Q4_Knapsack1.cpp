#include<bits/stdc++.h>
using namespace std;
#define ll  long long int

int f(int n, int wt, vector<int> w, vector<int> v)
{
	if(wt == 0 || n < 0)
		return 0;
	if(wt - w[n] >= 0)
		return max(f(n-1, wt-w[n], w, v) + v[n], f(n-1, wt, w, v));
	else
		return f(n-1, wt, w, v);
	

}

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

	cout << f(n-1,wt, w, v);

}


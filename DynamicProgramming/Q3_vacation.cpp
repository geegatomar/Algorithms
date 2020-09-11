#include<bits/stdc++.h>
using namespace std;
#define ll  long long int

int f(int n, int last, vector<int> &a, vector<int> &b, vector<int> &c)
{
	if(n < 0)
		return 0;
	if(n == 0 || last == -1)
		return max({f(n-1, 0, a,b,c) + a[n] , f(n-1,1,a,b,c) + b[n] , f(n-1, 2,a,b,c) + c[n]});
	else if(last == 0)
		return max(f(n-1,1,a,b,c) + b[n] , f(n-1, 2,a,b,c) + c[n]);
	else if(last == 1)
		return max(f(n-1, 0, a,b,c) + a[n] , f(n-1,1,a,b,c) + c[n]);
	else return max(f(n-1, 0, a,b,c) + a[n] , f(n-1,1,a,b,c) + b[n]);
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, i, j;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	cout << f(n-1, -1, a, b, c);
	

}


#include<bits/stdc++.h>
using namespace std;

int f(int a, int n)
{
	if(n == 1)
		return a;
	if(n <= 0)
		return 1;
	int x = f(a, n/2);
	if(n % 2 == 0)
		return x*x;
	else
		return x*x*a;
}

int main()
{
	int i, j, n, m, a;
	cin >> a >> n;        // calc a power n using divide and conquer ( fast eponentiation ) ( O (logn) )
	cout << f(a, n) << endl;
}

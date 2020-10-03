#include<bits/stdc++.h>
using namespace std;
//#define long long int long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
int n, m, k, dots = 0, cou = 0, yes = 0, d, r;
int a, b;
const int siz = 1e6 + 5;
long long int factmod[siz];

bool isvalid(int n)
{
	while(n > 0)
	{
		if(!(n % 10 == a || n % 10 == b))
			return false;
		n /= 10;
	}
	return true;
}


long long int power(long long int a, long long int n)     // a power n
{
	if(n == 0)
		return 1;
	if(n == 1)
		return a;
	long long int y = power(a, n/2);
	//cout << a << " " << n << " " << y << endl;
	if(n % 2 == 0)
		return (y%M * y%M)%M;
	else
		return (a%M * (y%M * y%M)%M)%M;
}

long long int ncr(int n, int r)
{
	// nca = (n!) % M  * (r!)^(m-2) % M * ((n-r)!)^(m-2) % M
	long long int nfact = factmod[n];
	long long int rfact = factmod[r];
	long long int n_minus_rfact = factmod[n-r];
	//cout << n << " " << r << "    " << nfact << " " << rfact << " " << n_minus_rfact << endl;
	rfact = power(rfact, M-2);
	n_minus_rfact = power(n_minus_rfact, M-2);
	return ((nfact%M * rfact%M)%M * n_minus_rfact%M)%M;
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, lim, q, p,mn = INT_MAX, mx = INT_MIN,j,x,y, t, sum = 0, sal = 0, ii, jj, cnt= 0;
	
	cin >> a >> b >> n;
	long long int ans = 0;
	
	for(long long int i = 1; i <= siz; i++)
	{
		factmod[i] = (factmod[i-1] * i) % M;
	}
	for(i = 0; i <= n; i++)           // iterating over the number of a's
	{
		sum = a*i + b*(n-i);
		if(isvalid(sum))
		{
			//cout << i << " " << n-i <<endl;
			ans += ncr(n, i);
			ans %= M;
		}
	}
	cout << ans;
	
}	 

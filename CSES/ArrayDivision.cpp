#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
#define inf INT_MAX-100
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, t;
vector<int> v;

// Its a BINARY SEARCH question!! (Its actually same as the one explained by Aditya Vermas BS video)

bool isval(int mid)
{
	int i = 0, ss = 0, cnt = 0, f = 0;
	while(i < n)
	{
		ss = 0;
		f = 0;
		cnt++;
		while(ss + v[i] <= mid)
		{
			f = 1;
			ss += v[i];
			i++;
		}
		if(!f)
			i++;
	}
	return cnt <= k;
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll  sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0;
	cin >> n >> k;
	v.resize(n);
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int low = 0, high = 10000, mid;
	while(low <= high)
	{
		
		mid = (low + high)/2;
		if(isval(mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << ans;

}	 

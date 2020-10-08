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


int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll  sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0;
	cin >> n;
	vector<int> v(n);
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
		if(i != 0)
			v[i] += v[i-1];                // now it stores prefix sum
	}
	map<int, int> mp;
	mp[0]++;
	for(i = 0; i < n; i++)
	{
		int s = v[i] % n;         // imp to take mod n
		ans += mp[s];
		mp[s]++;
	}
	cout << ans;

}	 

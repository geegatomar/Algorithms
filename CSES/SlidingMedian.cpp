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
	v.resize(n + 1);
	for(i = 0; i < n; i++)
		cin >> v[i];

	// O(NlogK)      ---> using a multiset (each time it contains only k elements)
	multiset<int> s;
	for(i = 0; i < k; i++)
		s.insert(v[i]);
	for(i = k; i <= n; i++)
	{
		cout << *next(s.begin(), k/2) << " ";  // IMP: use of next to move iterator by k/2 positions to get to the median
		s.erase(s.lower_bound(v[i-k]));      // IMP: when you want to erase only single occurrence
		s.insert(v[i]);
	
	}

}	 

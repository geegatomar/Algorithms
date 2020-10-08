#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
#define inf M-100
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;
vector<int> v;
vector<int> val, w;

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif

	// THIS SOLUTION IS O(NLOGN)
	// NORMAL DP SOLUTION IS N^2 FOR THIS, BUT USING HASHING IN MAPS, WE DO IT IN O(NLOGN)  (IMP)

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll  sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b;
	cin >> n;
	v.resize(n);
	vector<int> res(n, 1);
	multimap<int, int> mp;
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
		
	}
	for(i = 1; i < n; i++)
	{
		auto it = mp.lower_bound(v[i]);
		if(mp.size() == 0 || it == mp.begin())
		{
			//mp[v[i]] = 1;
			mp.insert(make_pair(v[i], 1));
		}
		else
		{
			it--;
			//mp[v[i]] = it->second + 1;
			cout << i << " " << v[i] << "     " << it->first << " " << it->second << endl;
			mp.insert(make_pair(v[i], it->second + 1));
		}
	}
	for(auto p : mp)
		cout << p.first << " " << p.second << endl;
	
}

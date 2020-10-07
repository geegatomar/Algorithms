#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1000000007;
#define PI 3.14159265358979
#define inf INT_MAX-100
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r;

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j, t, sum = 0, sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	cin >> n;
	map<int, int> mp;      // mp stores the (right lim, room no)          
	int room = 1;
	for(i = 0; i < n; i++)
	{
		cin >> l >> r;
		auto it = mp.lower_bound(l);

		if(mp.empty() || it == mp.begin())
		{
			//cout << "Inserting :  mp[" << r << "] = " << room << endl; 
			mp[r] = room;
			cout << room << " ";
			room++;
		}
		else
		{
			it--;
			int tmp = mp[it -> first];
			//cout << "Removing :  mp[" << it->first << "] = " << tmp << endl; 
			mp.erase(it);
			mp[r] = tmp;
			cout << tmp << " ";

		}
	}

	
}	 

#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pi, int> ppi;
//const int M = 100;
const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf M-100
const ll MM = 998244353;
const ll lim = 3e6 + 5, lim2 = 1e9;
const ll hi = 1e18;
ll n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt;	


int main()
{
 
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
 	ios::sync_with_stdio(false);
  	cin.tie(0);
	ll  sal = 0, ii, jj, x, y, l, r;
	ll  i, p,mn = INT_MAX, mx = INT_MIN,j, sum = 0, a, b, q, t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> v(n + 1);
		vector<vector<int>> where(n + 1);
		for(i = 1; i <= n; i++)
		{
			cin >> v[i];
			where[v[i]].push_back(i);
		}
		
		vector<int> res(n + 1, n + 1);
		for(int i = 1; i <= n; i++)
		{
			int mx = -1, prev = 0;
			where[i].push_back(n + 1);
			for(auto pos : where[i])
			{
				if(pos == 3)
				{
					cout <<"..." << pos << " " << prev << " " << pos-prev+1 << "\n";
				}
				mx = max(mx, pos - prev);
				prev = pos;
			}
			if(mx < 0 || mx > n)
				continue;
			cout << mx << " " << i << " " << where[i][0] << endl;
			for(mx; mx <= n; mx++)
			{
				res[mx] = min(res[mx], i);
			}
		}

		int prev = -1;
		for(i = 1; i <= n; i++)
		{
			if(res[i] == n+1)
			{
				res[i] = -1;
			}
			
			cout << res[i] << " ";
		}
		cout << "\n";
	}

 }

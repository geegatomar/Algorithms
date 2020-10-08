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


int f(int l, int r, int turn)
{
	// if turn == 0: (player 1's turn), we add his score, else we subtract for player 2's
	// eventually return max of this score
	if(l > r)
		return 0;
	if(turn == 0)
		return max(f(l+1, r, !turn) + v[l], f(l, r-1, !turn) + v[r]);
	else
		return min(f(l+1, r, !turn) - v[l], f(l, r-1, !turn) - v[r]);
}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("op2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll  sal = 0, ii, jj, cnt= 0, x, y, ans = 0, l, r;
	ll i, lim,  p,mn = INT_MAX, mx = INT_MIN,j,sum = 0, a, b;
	cin >> n;
	v.resize(n);
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	cout << (f(0, n-1, 0) + sum)/2;

}

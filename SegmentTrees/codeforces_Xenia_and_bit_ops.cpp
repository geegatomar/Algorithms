// in this question, one more variable to note in the functions we call is the 'lev' variable for level
// using this 'lev' variable and the total number of levels in the tree, we can determine if the current operation to be performed is OR or XOR

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
typedef pair<int, int> pi;
const int M = 1e8;
int n;
vector<int> tree, a;

void build(int node, int s, int e, int lev)
{
	if(s == e)
	{
		tree[node] = a[s];
		return;
	}
	int mid = (s + e)/2;
	build(2 * node, s, mid, lev + 1);
	build(2 * node + 1, mid + 1, e, lev+1);
	if(n % 2 != 0) // odd levels
	{
		if(lev % 2 == 0)     // OR
		{
			tree[node] = tree[2*node] | tree[2*node + 1];
		}
		else
			tree[node] = tree[2*node] ^ tree[2*node + 1];
	}
	else
	{
		if(lev % 2 == 0)     
		{
			tree[node] = tree[2*node] ^ tree[2*node + 1];
		}
		else
			tree[node] = tree[2*node] | tree[2*node + 1];
	}
}

void update(int node, int s, int e, int pos, int val, int lev)
{
	if(pos < s || pos > e)
		return;
	if(s == e)
	{
		tree[node] = val;          // this is the leaf node to be updated
		return;
	}
	int mid = (s + e)/2;
	// call both children if theres partial overlap
	update(2*node, s, mid, pos, val, lev + 1);
	update(2*node + 1, mid + 1, e, pos, val, lev + 1);
	if(n % 2 != 0) // odd levels
	{
		if(lev % 2 == 0)     // OR
		{
			tree[node] = tree[2*node] | tree[2*node + 1];
		}
		else
			tree[node] = tree[2*node] ^ tree[2*node + 1];
	}
	else
	{
		if(lev % 2 == 0)     
		{
			tree[node] = tree[2*node] ^ tree[2*node + 1];
		}
		else
			tree[node] = tree[2*node] | tree[2*node + 1];
	}

}

int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll i, q, m,mn = INT_MAX, mx = 1,k,  j, cnt=0, b = -1, x, y, t, sum = 0, val = 0;
	cin >> n >> m;
	int N = (1 << n);          // N number of elements
	tree.resize(4*N + 1);
	a.resize(N + 1);
	for(i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	build(1, 1, N, 0);
	while(m--)
	{
		cin >> x >> y;
		update(1, 1, N, x, y, 0);
		cout << tree[1] << endl;
	}


}

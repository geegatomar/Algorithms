#include<bits/stdc++.h>
using namespace std;
int a[100], tree[400], lazy[400];

void build(int node, int s, int e)
{
	if(s == e)
	{
		tree[node] = a[s];
		return;
	}
	int mid = (s + e)/2;

	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int s, int e, int l, int r, int val)                // update range using lazy
{
	if(l > r)
		return;

	// before looking at our 2 cases(conditions), we need to first handle lazy-ness of current node
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(s != e)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	// no overlap
	if(r < s || l > e)
		return;

	// complete overlap
	if(s >= l && e <= r)
	{
		tree[node] += val;
		if(s != e)
		{
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}

	int mid = (s + e)/2;
	update(2 * node, s, mid, l, r, val);
       	update(2 * node + 1, mid + 1, e, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
		
}

int query(int node, int s, int e, int l, int r)
{
	if(l > r)
		return 0;
	if(lazy[node] != 0)     // means theres something to propagate downwards
	{
		tree[node] += lazy[node];
		if(s != e)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(s > r || l > e)
		return 0;
	if(s >= l && e <= r)
		return tree[node];
	int mid = (s + e)/2;
	return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
}

int main()
{
	int i, j, n, m;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	update(1, 1, n, 3, 4, 100);
	update(1, 1, n, 4, 6, 1000);
	cout << query(1, 1, n, 5, 7) << endl;
}

// NOT SURE IF WORKING FINE (check Tushar Roy YT video for Lazy Propagation code)

#include<bits/stdc++.h>
using namespace std;
vector<int> a, tree, lazy;

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
}

void range_update(int node, int s, int e, int l, int r, int val)
{
	if(l > r)
		return;

	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(s != e)                // its not a leaf node, then pass lazy value to its children
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(l > e || s > r)        // no overlap condition
		return;

	if(s >= l && e <= r)      // total overlap condition
	{
		tree[node] += val;
		if(s != e)
		{
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}
	
	// otherwise, partial overlap condition
	
	int mid = (s + e)/2;
	range_update(2 * node, s, mid, l, r, val);
	range_update(2 * node + 1, mid + 1, e, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];

}

int range_query(int node, int s, int e, int l, int r)
{
	if(l > r)
		return 0;

	// make sure all propagation is done at position node. If not, update tree at pos(node) and mark its child		ren for lazy
	
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(s != e)                   // its not a leaf node
		{
			lazy[2 * node] += lazy[node];
		        lazy[2 * node + 1] += lazy[node];	
		}
		lazy[node] = 0;
	}

	if(l > e || s > r)           // no overlap
		return 0;
	
	if(s >= l && e <= r)          // complete overlap
		return tree[node];

	// partial overlap
	int mid = (s + e)/2;
	return range_query(2 * node, s, mid, l, r) + range_query(2 * node + 1, mid + 1, e, l, r);
}

int main()
{
	int i, j, n;
	n = 8;
	a.resize(n + 1);
	tree.resize(4 * n + 1);
	lazy.resize(4 * n + 1);
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	build(1, 1, n);
	int l, r, val;
	
	range_update(1, 1, n, 5, 7, 500);               // lazy range update
	range_update(1, 1, n, 2, 4, 1000);
	cout << range_query(1, 1, n, 3, 4) << endl;         // lazy range query

}

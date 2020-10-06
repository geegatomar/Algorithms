#include<bits/stdc++.h>
using namespace std;

vector<int> a, tree;

void build(int node, int start, int end)              // ===> O(n)
{
	if(start == end)
	{
		tree[node] = a[start];
		return;
	}

	int mid = start + (end - start)/2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)  // ===> O(nlogn)
{
	if(start > r || end < l)
		return 0;
	if(start >= l && end <= r)
		return tree[node];
	
	int mid = start + (end - start)/2;

	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int pos, int val)   // ===> O(nlogn)
{
	
	if(pos > end || pos < start)
		return;
	tree[node] += val;
	if(start == end)
		return;
	int mid = start + (end - start)/2;
	update(2 * node, start, mid, pos, val);
	update(2 * node + 1, mid + 1, end, pos, val);	
}

void update_range(int node, int s, int e, int l, int r, int val)      // ===> O(n)
{
	if(l > e || r < s)
		return;
	if(s == e)
	{
		tree[node] += val;
		return;
	}
	int mid = s + (e - s)/2;
	update_range(2 * node, s, mid, l, r, val);
	update_range(2 * node + 1, mid + 1, e, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
	int n, i, j, m;
	cin >> n;
	a.resize(n + 1);
	tree.resize(4*n + 1);
	for(i = 1; i <= n; i++)
		cin >> a[i];
	
	build(1, 1, n);
	/*
	for(auto e : tree)
		cout << e << " ";
	cout << endl;
	cout << "Enter query range: ";
	int l, r;
	cin >> l >> r;
	cout << query(1, 1, n, l, r) << endl;
	cout << "Enter update value and position : ";
	int pos, val;
	cin >> val >> pos;
	update(1, 1, n, pos, val);
	for(auto e : tree)
                cout << e << " ";
        cout << endl;
	*/
	cout << "Enter val to update range and l and r: ";
	int l, r, val;
	cin >> val >> l >> r;
	update_range(1, 1, n, l, r, val);
	for(auto e: tree)
		cout << e << " ";
	cout << endl;

}

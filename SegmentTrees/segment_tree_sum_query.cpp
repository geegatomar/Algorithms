#include<bits/stdc++.h>
using namespace std;

vector<int> a, tree;

void build(int node, int s, int e)        // s -> start,     e -> end
{
	if(s == e)
	{
		tree[node] = a[s];
		return;
	}
	int mid = (s + e)/2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	tree[node] = tree[2*node] + tree[2*node + 1];
}

int get_sum(int node, int s, int e, int l, int r)
{
	//cout << s << " " << e << " " << l << " " << r << endl;
	if(s >= l && e <= r)
		return tree[node];
	if(l > e || r < s)
		return 0;
	// else if theres partial overlap, call this function on both children
	int mid = (s + e)/2;

	return get_sum(2*node, s, mid, l, r) + get_sum(2*node + 1, mid + 1, e, l, r);
}

void update(int node, int s, int e, int pos, int val)
{
	if(pos > e || pos < s)
		return;
	tree[node] += val;
	if(s == e)
		return;
	int mid = (s + e)/2;
	update(2*node, s, mid, pos, val);
	update(2*node +1, mid+1, e, pos, val);
}

int main()
{
	int n, i;
	cin >> n;
	a.resize(n+1);
	for(i = 1; i <= n; i++)
		cin >> a[i];
	tree.resize(4*n+1);
	build(1, 1, n);
	for(i = 0; i <= 4*n; i++)
		cout << tree[i] << " ";
	cout << endl;
	//cout << get_sum(1, 1, n, 2, 4);
	update(1, 1, n, 3, 100);
	for(auto e:  tree)
		cout << e << " ";
	cout << endl;
}



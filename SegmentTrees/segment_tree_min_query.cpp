#include<bits/stdc++.h>
using namespace std;

vector<int> a, tree;

void build(int node, int s, int e)              // s : start, e : end
{
	if(s == e)       
	{
		tree[node] = a[s];
		return;
	}
	int mid = (s + e)/2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid +1, e);
	tree[node] = min(tree[2*node], tree[2*node + 1]);

}

void update(int node, int s, int e, int pos, int val)
{
	if(pos < s || pos > e)
		return;
	tree[node] += val;	
	if(s == e)
		return;
	int mid = (s + e)/2;
	update(2*node, s, mid, pos, val);
	update(2*node + 1, mid + 1, e, pos, val);
}

int get_min(int node, int s, int e, int l, int r)
{
	if(s >= l && e <= r)
	{
		return tree[node];
	}
	if(s > r || e < l)
		return 100000;
	int mid = (s + e)/2;
	return min(get_min(2*node, s, mid, l, r), get_min(2*node+1, mid+1, e, l, r));
}

int main()
{
	int i, n;
	cin >> n;
	a.resize(n + 1);
	tree.resize(4*n + 1);
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	build(1, 1, n);
	for(auto e: tree)
		cout << e << " ";
	cout << endl;
	update(1, 1, n, 3, -1000);         // increase the third positions val by -1000
	for(auto e: tree)
                cout << e << " ";
	cout << endl;

	cout << get_min(1, 1, n, 3, 6);    // get min from range (3, 6) inclusive
}



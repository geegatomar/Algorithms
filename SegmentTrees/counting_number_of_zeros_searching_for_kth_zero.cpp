#include<bits/stdc++.h>
using namespace std;
vector<int> a, tree;

void build(int node, int s, int e)
{
	if(s == e)
	{
		tree[node] = (a[s] == 0 ? 1 : 0);
		return;
	}
	int mid = (s + e)/2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int find_kth(int node, int s, int e, int k)
{

	if(k > tree[node])
		return -1;
	if(s == e)
		return tree[node];

	int mid = (s + e)/2;

	if(k <= tree[2 * node])
	{
		return find_kth(2 * node, s, mid, k);
	}
	else
	{
		return find_kth(2 * node + 1, mid + 1, e, k - tree[2 * node]);
	}
}

int main()
{
	int i, j, n = 9;
	a.resize(n + 1);
	tree.resize(4*n + 1);
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	cout << "4th zero : " << find_kth(1, 1, n, 4) << endl;
	cout << "6th zero : " << find_kth(1, 1, n, 6) << endl;
	cout << "3rd zero : " << find_kth(1, 1, n, 3) << endl;
}



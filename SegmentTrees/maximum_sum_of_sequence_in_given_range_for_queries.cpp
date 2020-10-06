#include<bits/stdc++.h>
using namespace std;
int a[100005];

struct data
{
	int sum, pref, suff, ans;
};

data tree[4*100005];

data combine(data l, data r)
{
	data res;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.sum = l.sum + r.sum;
	res.ans = max({l.ans, r.ans, r.pref + l.suff});
	return res;
}

void build(int node, int s, int e)
{
	if(s == e)
	{
		tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = a[s];
		return;
	}
	int mid = (s + e)/2;
	build(2 * node, s, mid);
	build(2 * node, mid + 1, e);
	tree[node] = combine(tree[2*node], tree[2*node + 1]);
}

data query(int node, int s, int e, int l, int r)
{
	data dum;
	dum.ans = dum.pref = dum.suff = dum.sum = INT_MIN;
	if(r < s || l > e)
		return dum;
	if(r >= e  && s <= l)
		return tree[node];
	int mid = (s + e)/2;
	if(r <= mid)
		return query(2 * node, s, mid, l, r);
	if(l > mid)
		return query(2 * node + 1, mid + 1, e, l, r);
	return combine(query(2*node, s, mid, l, r), query(2*node + 1, mid + 1, e, l, r));
}

int main()
{
	int i, j, n, m;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		cout << query(1, 1, n, x, y).ans << "\n";
	}
}



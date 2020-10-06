#include<bits/stdc++.h>
using namespace std;

int a[100005];

struct data
{
	int cnt1, cnt2, cnt0;
};

data tree[400005];

data make_data(int val)
{
	data res;
	res.cnt0 = res.cnt1 = res.cnt2 = 0;
	val = val % 3;
	if(val == 1)
		res.cnt1 += 1;
	else if(val == 2)
		res.cnt2 += 1;
	else
		res.cnt0 += 1;
	return res;
	
}

data combine(data l, data r)               // combine takes data of left subtree and right subtree
{
	data res;
	res.cnt0 = l.cnt0 + r.cnt0;
	res.cnt1 = l.cnt1 + r.cnt1;
	res.cnt2 = l.cnt2 + r.cnt2;
	return res;
}

void build(int node, int s, int e)
{
	if(s == e)
	{
		tree[node] = make_data(a[s]);
		return;
	}
	int mid = (s + e)/2;

	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

void point_update(int node, int s, int e, int pos)
{
	if(pos < s || pos > e)
		return;
	
	int mid = (s + e)/2;
	point_update(2 * node, s, mid, pos);
	point_update(2 * node + 1, mid + 1, e, pos);
}

int main()
{
	int i, j, n, m;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> a[i];
}

#include<bits/stdc++.h>
using namespace std;
int a[1000];

struct data
{
	int max1, max2;              // largest and second largest value in that range
};

data tree[4000];

data combine(data l, data r)
{
	data res;
	res.max1 = max(l.max1, r.max1);
	if(res.max1 == l.max1)
		res.max2 = max(r.max1, l.max2);
	else
		res.max2 = max(l.max1, r.max2);
	return res;
}

void build(int node, int s, int e)
{
	if(s == e)
	{
		tree[node].max1 = a[s];
		tree[node].max2 = 0;
		return;
	}

	int mid = (s + e)/2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	tree[node] = combine(tree[2 * node], tree[2 * node + 1]);

}

data query(int node, int s, int e, int l, int r)
{
	data res;
	res.max1 = 0;
	res.max2 = 0;
	if(l > e || r < s || l > r)
		return res;
	if(s >= l && e <= r)
		return tree[node];
	int mid = (s + e)/2;
	return combine(query(2 * node, s, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
}

int main()
{
	int i, j, n;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	data ans = query(1, 1, n, 2, 2);
	cout << ans.max1 << " " << ans.max2 << endl;
}

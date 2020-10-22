#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N];

struct data
{
	int pp, pm, mp, mm;
	data()
	{
		data(0, 0, 0, 0);
	}
	data(int pp, int pm, int mp, int mm)
	{
		this->pp = pp;
		this->mp = mp;
		this->pm = pm;
		this->mm = mm;
	}
};

struct data tree[4*N + 1];

data make_data(int val)
{
	return data(val, 0, 0, -val);
}

data combine(data l, data r)
{
	data res;
	res.pp = max({l.pp + r.mp, l.pm + r.pp});
	res.pm = max({l.pp + r.mm, l.pm + r.pm});
	res.mp = max({l.mp + r.mp, l.mm + r.pp});
	res.mm = max({l.mm + r.pm, l.mp + r.mm});
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
	build(2*node, s, mid);
	build(2*node + 1, mid + 1, e);
	tree[node] = combine(tree[2*node], tree[2*node + 1]);
}

void update(int node, int s, int e, int pos, int val)
{
	if(pos < s || pos > e)
		return;
	if(s == e && pos == s)
	{
		tree[node] = make_data(val);       // note: its assignment, not update
		return;
	}

	int mid = (s + e)/2;
	if(pos <= mid)
		update(2 * node, s, mid, pos, val);
	else
		update(2 * node + 1, mid + 1, e, pos, val);

	tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
	int i, j, n, t;
	cin >> t;
	while(t--)
	{
		int n, q;
		cin >> n >> q;
		for(i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		build(1, 1, n);
		for(i = 0; i <= q; i++)
		{
			data ans = tree[1];
			int mx = max({ans.pp, ans.pm, ans.mp, ans.mm});
			cout << mx << endl;
			if(i == q)
				break;
			int l, r;
                        cin >> l >> r;
			update(1, 1, n, l, a[r]);
			update(1, 1, n, r, a[l]);
			swap(a[l], a[r]);
		}
	}
	
}

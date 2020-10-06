#include<bits/stdc++.h>
using namespace std;
int a[100000];

struct segment
{
	int pref_sum, suff_sum, total_sum, max_sum;
	
	void combine(segment left, segment right)
	{
		pref_sum = max(left.pref_sum, left.total_sum + right.pref_sum);
		suff_sum = max(right.suff_sum, left.suff_sum + right.total_sum);
		total_sum = left.total_sum + right.total_sum;
		max_sum = max({pref_sum, suff_sum, total_sum, left.max_sum, right.max_sum, 
				left.suff_sum + right.pref_sum });
	}

}seg[4*100000 + 1];

void build(int node, int s, int e)
{
	if(s == e)
	{
		seg[node].pref_sum = seg[node].suff_sum = seg[node].total_sum = seg[node].max_sum = a[s];
		return;
	}
	int mid = (s + e)/2;
	build(2 * node, s, mid);
	build(2 * node + 1, mid + 1, e);
	seg[node].combine(seg[2 * node], seg[2 * node + 1]);
}

segment query(int node, int s, int e, int l, int r)
{
	segment ans;
	ans.pref_sum = ans.suff_sum = ans.total_sum = ans.max_sum = INT_MIN;
	if(l > e || r < s || l > r)
		return ans;
	if(l >= s && r <= e)
		return seg[node];
	int mid = (s + e)/2;
	if(r <= mid)                                          // means my ans is completely on left side
		return query(2 * node, s, mid, l, r);          
	if(l > mid)
		return query(2 * node + 1, mid + 1, e, l, r);
	
	// else its partial overlap
	ans.combine(query(2*node, s, mid, l, mid), query(2*node + 1, mid + 1, e, mid + 1, r));
	return ans;
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
		cout << query(1, 1, n, x, y).max_sum << "\n";
	}
}

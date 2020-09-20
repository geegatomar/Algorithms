#include<bits/stdc++.h>
using namespace std;
vector<int> a, tree;

// here s and e represent the ranges of values stored by that 'node' from s(start) to e(end)

void build(int node, int s, int e)
{
	if(s == e)                      // base case for leaf nodes
	{
		tree[node] = a[s];
		return;
	}

	int mid = (s + e)/2;

	build(2*node, s, mid);
	build(2*node + 1, mid+1, e);
	
	tree[node] = tree[2*node] + tree[2*node + 1];
}

void update(int node, int s, int e, int pos, int val)           // to replace(update) position with value val
{
	if(pos < s || pos > e)            // no overlap
	{
		return;
	}
	if(s == e)                        // reached the leaf node (node we are looking for)
	{
		tree[node] = val;
		return;
	}
	// above two cases were base cases
	
	// partial overlap, then call recursively on both children to go looking for it
	
	int mid = (s + e)/2;
       	update(2*node, s, mid, pos, val);
	update(2*node + 1, mid +1, e, pos, val);
	tree[node] = tree[2*node] + tree[2*node + 1];	
}

int get_sum(int node, int s, int e, int l, int r)           // l to r is the range of sum I need
							    // s and e are the range stored by the current node
{
	// BASE CASE :if the current node I'm at is completely inside the range (l, r), then it needs to be taken fully, directly
	
	if(s >= l && e <= r)
		return tree[node];
	
	// no overlap base case
	if(s > r || e < l)
		return 0;
	
	// else it is the case of partial overlap, so we obtain answers from both children and return their result together (strategy is similiar to the one followed by divide and conquer)
	
	int mid = (s + e)/2;
	int leftAns = get_sum(2*node, s, mid, l, r);
	int rightAns = get_sum(2*node + 1, mid + 1, e, l, r);
	return leftAns + rightAns;
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
//	update(1, 1, n, 4, 1000);
	for(auto e: tree)
                cout << e << " ";
	cout << endl;
	
	cout << get_sum(1, 1, n, 3, 5) << endl;
}


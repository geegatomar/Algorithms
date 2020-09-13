#include<bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> tree;

void build(int node, int start, int end)
{
	//cout << node << "   " << start << " " << end << endl;
	if(start == end)                // then its a root node
		tree[node] = A[start];
	else
	{
		int mid = start + (end-start)/2;

		build(2*node, start, mid);
		build(2*node + 1, mid+1, end);
		tree[node] = tree[node*2] + tree[node*2 + 1];
	}
}

void update(int node, int start, int end, int idx, int val)
{
	if(start == end)
	{
		// leaf node
		A[idx] += val;
		tree[node] += val;
		return;
	}

	int mid = (start + end)/2;

	if(idx >= start && idx <= mid)
	{
		update(2*node, start, mid, idx, val);
	}
	else
		update(2*node + 1, mid+1, end, idx, val);

	tree[node] = tree[2*node] + tree[2*node + 1];
}

int main()
{
	vector<int> v{2, 3, -1, 5, -2, 4, 8, 10};
	A = v;
	int n = A.size();
	//cout << n << endl;
	tree.resize(2*n, 0);
	build(1, 0, n-1);
	
	for(auto e : tree)
		cout << e << " ";
	cout << endl;

	update(1, 0, n-1, 4, 10);
	// adding 10 to the 4th index position element

	for(auto e : tree)
		cout << e << " ";
	cout << endl;
}


#include<bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> tree;

void build(int node, int start, int end)
{
	cout << node << "   " << start << " " << end << endl;
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

int main()
{
	vector<int> v{2, 3, -1, 5, -2, 4, 8, 10};
	A = v;
	int n = A.size();
	cout << n << endl;
	tree.resize(2*n, 0);
	build(1, 0, n-1);
	for(auto e: tree)
	{
		cout << e << " ";
	}
	cout << endl;
}


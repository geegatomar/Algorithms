#include<bits/stdc++.h>
using namespace std;
int i, j, n, m, l, r;
const int inf = 1e9;
vector<int> v, b;        // b is the block array
int blk;   // block size

int get_min(int l, int r)
{
	int LB = l / blk;       // left block index
	int RB = r / blk;       // right block index
	int mn = inf;

	if(LB == RB)
	{
		for(i = l; i <= r; i++)
			mn = min(mn, v[i]);
		return mn;
	}

	for(i = l; i <= blk * (LB + 1); i++)
		mn = min(mn, v[i]);
	
	for(i = LB + 1; i < RB; i++)             // here we are looking at the blocks hence b[i]
		mn = min(mn, b[i]);
	
	for(i = blk * RB; i <= r; i++)
		mn = min(mn, v[i]);
	
	return mn;
}

int main()
{
	cin >> n;
	blk = sqrt(n) + 1;           // computing block-size
	v.resize(blk * blk);
	b.resize(blk);
	fill(v.begin(), v.end(), inf);
	
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
		b[i] = inf;
	}

	
	for(i = 0; i < n; i++)
	{
		b[i / blk] = min(b[i / blk], v[i]);
	}

	cout << "How many queries ? " ;
	int q;
	cin >> q;
	
	for(int i = 1; i <= q; i++)
	{
		cout << "Enter l and r for query " << i << " : ";
		cin >> l >> r;
		cout << get_min(l, r) << "\n";
	}
}

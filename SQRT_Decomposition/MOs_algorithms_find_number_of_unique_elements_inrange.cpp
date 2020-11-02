#include<bits/stdc++.h>
using namespace std;
int i, j, n, m, l, r, blk;

// Mo' algorithm is used to answer "offline" queries

struct query
{
	int l, r, idx;
};

query Q[1000];
int ar[1000], ans[1000], freq[1000];
int cnt = 0;

bool comp(query a, query b)
{
	if(a.l/blk != b.l/blk)               // if not in same block, sort by this
		return a.l/blk < b.l/blk;
	return a.r < b.r;
}

void add(int pos)
{
	freq[ar[pos]]++;
	if(freq[ar[pos]] == 1)
		cnt++;
}

void remove(int pos)
{
	freq[ar[pos]]--;
	if(freq[ar[pos]] == 0)
		cnt--;
}

int main()
{
	cin >> n;
	blk = sqrt(n) + 1;
	for(i = 0; i < n; i++)
		cin >> ar[i];
	cin >> q;
	for(i = 0; i < q; i++)
	{
		cin >> Q[i].l >> Q[i].r;
		Q[i].idx = i;
	}

	sort(Q, Q + q, comp);

	int ML = 0, MR = -1;
	for(int i = 0; i < q; i++)
	{
		int L = Q[i].l;       // l and r of the i'th query
		int R = Q[i].r;
		                      // these standard 4 while loops of Mo's algorithm
		while(ML > L)
			ML--, add(ML);
		while(MR < R)
			MR++, add(MR);
		while(ML < L)
			remove(ML), ML++;
		while(MR > R)
			remove(MR), MR--;
		
		ans[Q[i].idx] = cnt; 
	}
}

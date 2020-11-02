#include<bits/stdc++.h>
using namespace std;
int i, j, n, m, blk;
vector<int> v, b;

int get_sum(int l, int r)
{
	int LB = l / blk;         // index in which l lies in the b[] array
	int RB = r / blk;
	if(LB == RB)
	{
		int sum = 0;
		for(int i = l; i <= r; i++)
			sum += v[i];
		return sum;
	}
	
	int sum = 0;
	for(i = l; i < blk * (LB + 1); i++)
		sum += v[i];
	for(i = LB + 1; i < RB; i++)
		sum += b[i];
	for(i = blk * RB; i <= r; i++)
		sum += v[i];
	return sum;
}

int main()
{
	cin >> n;
	blk = sqrt(n) + 1;
	v.resize(blk * blk);
	b.resize(blk);
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
		b[i / blk] += v[i];
	}
	int q;
	cout << "Numb of queries ? ";
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cout << "Enter l and r ";
		int l, r;
		cin >> l >> r;
		cout << get_sum(l, r) << "\n";
	}
}

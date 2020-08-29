#include<bits/stdc++.h>
using namespace std;

int siz[100];
int par[100];

void make_set(int i)
{
	par[i] = i;
	siz[i] = 1;
}

int find_set(int i)
{
	if(i == par[i])
		return i;
	return par[i] = find_set(par[i]);
}

int union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(siz[a] < siz[b])
			swap(a, b);
		par[b] = a;
		siz[a] += siz[b];
	}
}

int main()
{
	int i, j, n;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		make_set(i);
	}
}


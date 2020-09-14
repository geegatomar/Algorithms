#include<bits/stdc++.h>
using namespace std;

int par[100];
int siz[100];

void make_set(int v)
{
	par[v] = v;
	siz[v] = 1;
}

int find_set(int v)
{
	if(par[v] == v)
		return v;
	return par[v] = find_set(par[v]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(siz[a] < siz[b])
			swap(a, b);
		siz[a] += siz[b];
		par[b] = a;
	}
}

int main()
{

}


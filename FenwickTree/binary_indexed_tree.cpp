#include<bits/stdc++.h>
using namespace std;

int sum(int i)
{
	int ans = 0;
	for( ; i > 0; i -= (i & -i))
	{
		ans += bit[i];
	}
	return ans;

}

void update(int i, int x)     // to add +x in the ith element (note: its adding, not replacing)
{
	for( ; i <= N; i += (i & -i))
	{
		bit[i] += x;
	}
}

// Note: In BIT, both the ends of the range are included, ie we always speak inclusive
// to do range sum: We'll call the above sum function as:  sum(r) - sum(l - 1)

int main()
{

}

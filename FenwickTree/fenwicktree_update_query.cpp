#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> BIT;

void update(int x, int delta)
{
	for(; x <= n; x += x&-x)
	{
		BIT[x] += delta;
	}
}

int query(int x)
{
	int sum = 0;
	for(; x > 0; x -= x&-x)
	{
		sum += BIT[x];
	}
	return sum;
}

int main()
{
	vector<int> v{0,3,0,5,6,1,2,1,3,4,6};
	n = v.size()-1;
	BIT.resize(n + 1);
	for(int i = 1; i <= n; i++)
	{
		update(i, v[i]);
	}
	for(auto e : BIT)
		cout << e << " ";
	cout << endl;
	cout << query(7) << endl;
	cout << "sum of all elements in range [2, 7] is " <<  query(7) - query(2-1) << endl;
}


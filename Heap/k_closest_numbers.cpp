#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main()
{
	vector<int> v{5, 6, 7, 8, 10, 7, 9};
	int i, j, n = v.size(), k = 3, x = 7;
	priority_queue<pi> maxh;
	for(i = 0; i < n; i++)
	{
		v[i] = abs(v[i] - x);
	}
	for(i = 0; i < n; i++)
	{
		maxh.push({v[i], i});
		if(maxh.size() > k)
		{
			maxh.pop();
		}
	}
	while(!maxh.empty())
	{
		int e = maxh.top().first, ind = maxh.top().second;
		cout << ind << endl;
		maxh.pop();
	}


}



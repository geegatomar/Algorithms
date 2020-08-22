#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v{6, 5, 3, 2, 8, 10, 9};
	int i, j, k = 4, n = v.size();
	vector<int> res;
	priority_queue<int, vector<int> , greater<int>> minh;
	for(i = 0; i < n; i++)
	{
		if(i < k)
		{
			minh.push(v[i]);
			continue;
		}
		int e = minh.top();
		minh.pop();
		res.push_back(e);
		minh.push(v[i]);
	}
	while(!minh.empty())
	{
		int e = minh.top();
                minh.pop();
                res.push_back(e);
	}
	for(auto e : res)
		cout << e << endl;

}


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

bool myComp(pi p1, pi p2)
{
	return p1.second > p2.second;
}

int main()
{
	vector<int> v{1, 1, 3, 1, 2, 4, 2, 5, 5, 5};
	int i, j, k = 2, n = v.size();
	map<int, int> mp;
	for(i = 0; i < n; i++)
	{
		if(mp.find(v[i]) == mp.end())
		{
			mp[v[i]] = 1;
		}
		else
			mp[v[i]]++;
	}
	//priority_queue<pi, vector<pi>, myComp> pq; // max heap
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	for(auto each_pair : mp)
	{
		pq.push({each_pair.second, each_pair.first});
		if(pq.size() > k)
			pq.pop();
	}
	while(!pq.empty())
	{
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

}


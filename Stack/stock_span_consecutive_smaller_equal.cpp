#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr{100, 80, 60, 70, 60, 75, 85};
	int i, j, n = arr.size();
	vector<int> res(n, 0);
	stack<pair<int, int>> st;      //stack to keep element and its index
	for(i = 0; i < n; i++)
	{
		while(!st.empty() && st.top().first <= arr[i])
			st.pop();
		if(st.empty())
			res[i] = i + 1;
		else
			res[i] = i - st.top().second;
		st.push({arr[i], i});
	}
	for(auto e : res)
		cout << e << " ";
	cout << endl;
}

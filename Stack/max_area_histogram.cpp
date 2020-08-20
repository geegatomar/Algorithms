#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr{6, 2, 5, 4, 5, 1, 6};
	int i, j, n = arr.size();
	vector<int> ns_left(n), ns_right(n);
	stack<pair<int, int>> st;
	for(i = 0; i < n; i++)
	{
		while(!st.empty() && st.top().first >= arr[i])
		       st.pop();
		if(st.empty())
			ns_left[i] = -1 ;
		else
			ns_left[i] = st.top().second;
		st.push({arr[i], i});
	}
	for(auto e : ns_left)
		cout << e << " ";
	cout << endl;
	stack<pair<int, int>> s;
	for(i = n-1; i >= 0; i--)
	{
		while(!s.empty() && s.top().first >= arr[i])
			s.pop();
		if(s.empty())
			ns_right[i] = n ;
		else
			ns_right[i] = s.top().second ;
		s.push({arr[i], i});
	}
	for(auto e: ns_right)
		cout << e << " ";
	cout << endl;
	int mx = 0;
	for(i = 0; i < n; i++)
	{
		int sum = arr[i] * (ns_right[i] - ns_left[i] - 1);
		cout << sum << " ";
		if(sum > mx)
			mx = sum;
	}
	cout << endl;
	cout << mx << endl;
}


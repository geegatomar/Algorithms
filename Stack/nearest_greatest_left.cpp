#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {1, 3, 2, 4, 1, 2};
	int i, j, n = 6;
	vector<int> res(n);
	stack<int> st;
	for(i = 0; i < n; i++)
	{
		while(!st.empty() && st.top() < arr[i])
			st.pop();
		if(st.empty())
		{
			res[i] = -1;
			st.push(arr[i]);
		}
		else
		{
			res[i] = st.top();
			st.push(arr[i]);
		}
	}
	for(auto e: res)
	{
		cout << e << " ";
	}
	cout << endl;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {10, 20, 13, 2, 14, 6, 5, 10, 8};
	int i, j, n = 9;
	vector<int> res(n);
	stack<int> st;
	for(i = 0; i < n; i++)
	{
		while(!st.empty() && arr[i] <= st.top())
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
	for(auto e : res)
		cout << e << " ";
	cout << endl;
}


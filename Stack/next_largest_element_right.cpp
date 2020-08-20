#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr{4, 5, 2, 10, 8};
	int i, j, n = arr.size();
	stack<int> st;
	vector<int> res(n);
	for(i = n-1; i >= 0; i--)
	{
		while(!st.empty() && st.top() <= arr[i])
                                st.pop();
		if(st.empty())
		{
			st.push(arr[i]);
			res[i] = -1;    // no element on its right is larger
		}
		else
		{
			res[i] = st.top();
			st.push(arr[i]);
		}
	}
	for(auto e: arr)
		cout << e <<  " ";
	cout << endl;
	for(auto e : res)
		cout << e << " ";
	cout << endl;
}



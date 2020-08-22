#include<bits/stdc++.h>
using namespace std;

void calc(string s, int n, string now, vector<string> &v)
{
	if(n < 0)
	{
		v.push_back(now);
		return;
	}
	calc(s, n-1, now + s[n], v);
	calc(s, n-1, now, v);
}	

int main()
{
	string s = "abcd";
	int i, j, n = s.size();
	vector<string> v;
	calc(s, n - 1, "", v);
	for(auto e: v)
		cout << e << endl;
}


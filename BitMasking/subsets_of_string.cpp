#include<bits/stdc++.h>
using namespace std;

void find(int mask, string s)
{
	int i, n = s.size();
	for(i = 0; i < n; i++)
	{
		int f = 1<<i;
		if(mask & f)
			cout << s[i];
	}
	cout << endl;
}

int main()
{
	string s = "abcd";
	cout << (1 << s.size()) << endl;
	for(int i = 0; i < (1 << s.size()); i++)
	{
		find(i, s);
	}
}


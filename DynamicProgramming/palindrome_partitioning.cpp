#include<bits/stdc++.h>
using namespace std;

int ispal(int i, int j, string s)
{
	if(i == j)
		return 1;
	//cout << "i: " << i << ", j: " << j << ", string : " << s << endl; 
	
	for(int t = 0; t < j-i-1; t++)
	{
		if(s[i + t] != s[j - t])
			return 0;
	}
	
/*
	while(i < j)
	{
		if(s[i] != s[j])
			return 0;
		i++;
		j--;
	}
	*/
	return 1;
}

int count(int i, int j, string s)
{
	if(i >= j)
		return 0;
	if(ispal(i, j, s))
		return 0;
	int mn = INT_MAX;
	for(int k = i; k < j; k++)
	{
		int temp = 1 + count(i, k, s) + count(k + 1, j, s);
		if(temp < mn)
			mn = temp;
	}
	return mn;
}

int main()
{
	string s = "ababbbabbababa";
	//s = "pppitin";
	int n = s.size(), i, j;
	cout << count(0, n-1, s);
}


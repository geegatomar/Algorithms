#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s = "How are you", word = "";
	int i = 0;
	while(i <= s.size())
	{
		if(s[i] == ' ' || i == s.size())
		{
			cout << word << endl;
			word = "";
		}
		else
		{
			word += s[i];
		}
		i++;
	}
}


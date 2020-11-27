#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int m, vector<int> &lps)
{
	int len = 0, i = 1;
	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			lps[i] = len + 1;
			len++, i++;
		}
		else
		{
			if(len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int KMPSearch(string pat, string txt)
{
	int n = txt.size(), m = pat.size();
	vector<int> lps(m, 0);
	computeLPS(pat, m, lps);
	int i = 0, j = 0;
	while(i < n - m + 1)
	{
		if(txt[i] == pat[i])
			i++, j++;
		else
		{
			if(j != 0)
				j = lps[j - 1];
			else
				i++;
		}
		if(j == m)
			return i - j;
	}
	return -1;
}

int main()
{
	string txt, pat;
	cin >> txt >> pat;
	cout << KMPSearch(pat, txt) << endl;
}

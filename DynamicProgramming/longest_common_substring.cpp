// Important: Note that this question's top-down is slightly different (not at straight -forwardas the others.

#include<bits/stdc++.h>
using namespace std;

int calc(int n, int m, string x, string y, int lcscount)
{
	if(n <= 0 || m <= 0)
		return 0;
	
	int lcsc1 = lcscount;

	if(x[n-1] == y[m-1])
		lcsc1 = calc(n-1, m-1, x, y, lcsc1 + 1);
	
	int lcsc2 = calc(n, m-1, x, y, 0);
	int lcsc3 = calc(n-1, m, x, y, 0);
	return max(lcsc1, max(lcsc2, lcsc3));
}

int main()
{
	string x = "abcdefthhh", y = "abfcefthiybahhi";
	int n = x.size(), m = y.size();
	cout << calc(n, m, x, y, 0);
}


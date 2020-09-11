#include<bits/stdc++.h>
using namespace std;

int calc(int i, int j, string x, bool isTrue)
{
	if(i > j)
		return 0;
	if(i == j)
	{
		if(isTrue)
		{
			if(x[i] == 'T')
				return 1;
			else
				return 0;
		}
		else
		{
			if(x[i] == 'T')
				return 0;
			else
				return 1;
		}
	}
	int ans = 0;
	for(int k = i + 1; k < j; k += 2)
	{
		int lT = calc(i, k - 1, x, true);
		int rT = calc(k + 1, j, x, true);
		int lF = calc(i, k - 1, x, false);
		int rF = calc(k + 1, j, x, false);
		
		if(x[k] == '|')
		{
			if(isTrue)
				ans += lT*rT + lF*rT + lT*rF;
			else
				ans += lF*rF;
		}
		else if(x[k] == '&')
		{
			if(isTrue)
				ans += lT*rT;
			else
				ans += lF*rF + lF*rT + lT*lF;
		}
		else
		{
			if(isTrue)
				ans += lT*rT + lF*rF;
			else
				ans += lT*rF + lF*rT;
		}
	}
	cout << i << " " << j << " ....... " << ans << endl;
	return ans;
		
}

int main()
{
	string x = "T|T&F^T";
	int n = x.size(), i, j;
	cout << calc(0, n-1, x, true);
}



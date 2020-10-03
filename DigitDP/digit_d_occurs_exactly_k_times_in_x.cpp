#include<bits/stdc++.h>
using namespace std;

int d, k;

int f(int pos, int tight, string num, int occd)      // occd is the occurences of digit d so far
{
	//cout << pos << "  " << tight << " " << occd << endl;
	if(pos == num.size())
	{
		if(occd == k)
			return 1;
		return 0;
	}
	if(tight)
	{
		int ans = 0;
		for(int i = 0; i <= num[pos]-'0'; i++)
		{
			if(i == num[pos]-'0')
			{
				if(i == d) ans += f(pos+1, 1, num, occd+1);
				else	ans += f(pos+1, 1, num, occd);
			}	
			else
			{
				if(i == d) ans += f(pos+1, 0, num, occd+1);
				else	ans += f(pos+1, 0, num, occd);
			}
		}
		return ans;
	}
	else
	{
		int ans = 0;
		for(int i = 0; i <= 9; i++)
		{
			if(i == d)
				ans += f(pos+1, 0, num, occd+1);
			else
				ans += f(pos+1, 0, num, occd);
		}
		return ans;
	}
	return 0;
}

int main()
{
	int l, r;
	cin >> l >> r >> d >> k;
	l--;
	string ll = to_string(l);
	string rr = to_string(r);
	//cout << f(0, 1, "44", 0) << endl << endl;
	cout << f(0, 1, rr, 0) - f(0, 1, ll, 0) << endl;
}

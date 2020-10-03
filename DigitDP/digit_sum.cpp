#include<bits/stdc++.h>
using namespace std;
string l, r;

int f(int pos, int tight, string num)
{
	cout << pos << " " << tight << "      , number: " << num << endl;
	if(pos >= num.size())
		return 0;
	if(tight)
	{
		int ans = 0;
		for(int i = 0; i <= num[pos]-'0'; i++)
		{
			if(i == num[pos]-'0')
				ans += f(pos + 1, 1, num) + i;
			else
				ans += f(pos + 1, 0, num) + i;
		}
		return ans;
	}
	else
	{
		int ans = 0;
		for(int i = 0; i <= 9; i++)
		{
			ans += f(pos + 1, 0, num) + i;
		}
		return ans;
	}
}

int main()
{
	cin >> r >> l;
	cout << f(0, 1, "8") << endl << endl;
	cout << f(0, 1, r) - f(0, 1, l) << endl;
}

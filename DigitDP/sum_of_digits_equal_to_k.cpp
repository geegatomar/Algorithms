#include<bits/stdc++.h>
using namespace std;
int k;

int f(int pos, int tight, string num, int sum)             // tight represents restriction
{
	//cout << pos << " " << tight << " " << sum << endl;
	if(sum > k)
		return 0;
	if(pos == num.size())
		return sum == k;
	if(tight)
	{
		int cnt = 0;
		for(int i = 0; i <= num[pos]-'0'; i++)
		{
			if(i == num[pos]-'0')
				cnt += f(pos+1, 1, num, sum+i);
			else
				cnt += f(pos+1, 0, num, sum+i);	
		}
		return cnt;
	}
	else
	{
		int cnt = 0;
		for(int i = 0; i <= 9; i++)
		{
			cnt += f(pos+1, 0, num, sum+i);
		}
		return cnt;
	}
	return 0;
}

int main()
{
	int l, r;
	cin >> l >> r >> k;
	l--;
	string ll = to_string(l);
	string rr = to_string(r);
	//cout << f(0, 1, rr, 0) << endl;
	cout << f(0, 1, rr, 0) - f(0, 1, ll, 0) << endl;
}

#include<bits/stdc++.h>
using namespace std;

int tobin(int n)
{
	int b = 0, i = 1;
	while(n)
	{
		b = b + i*(n%2);
		n/=2;
		i*=10;
	}
	return b;
}

int main()
{
	int n = 11;  // 1011
	int j = 1;
	int mask = (1 << j);
	//cout << tobin(13) << endl;
	cout << tobin(~(mask) & n) << endl;
}



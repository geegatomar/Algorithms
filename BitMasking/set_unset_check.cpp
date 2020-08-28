#include<bits/stdc++.h>
using namespace std;

int to_bin(int n, int i)
{
	if(n <= 0)
		return 0;
	return i*(n%2) + to_bin(n / 2, 10*i);
}

int sett(int pos, int n)
{
	int mask = 1 << pos;
	return mask|n;
}

int unset(int pos, int n)
{
	int mask = 1 << pos;
	return mask^n;
}

int main()
{
	int i, j, n = 17;
	cout << n << " "<< to_bin(n, 1) << endl;
	cout << sett(3, n) << endl;
	cout << to_bin(sett(3, n), 1) << endl;
	cout << unset(3, sett(3, n)) << endl;
	cout << to_bin(unset(3,n), 1) << endl;
	//check(3);
}

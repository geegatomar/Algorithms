#include<bits/stdc++.h>
using namespace std;
const int M = 100;

int f(int a, int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return a;
	int y = f(a, n/2);
	if(n % 2 == 0)
		return ((y % M) * ( y % M)) % M;
	else return (a * (((y % M) * ( y % M))) % M);
}


int main()
{
	int i, j, n, a;           // calculate ( a ^ n ) % M
	cin >> a >> n;
	cout << f(a, n) << endl;

}


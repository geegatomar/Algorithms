#include<bits/stdc++.h>
using namespace std;

// n persons and m jobs

int calc(int n, int m, int mask, int a[4][4])
{
	if(n < 0)
		return 0;
	int mn = INT_MAX;
	for(int i = 0; i < m; i++)
	{
		// if job is not already taken
		if(!(mask & (1 << i)))
		{
		//	cout << "n: "<< n << ", i: "<< i << " *** " <<  calc(n-1, m, (mask|(1<<i)), a) + a[n][i] << endl;
			mn = min(mn, calc(n-1, m, (mask |(1 << i)), a) + a[n][i]);
		}
	}
	return mn;

}

int main()
{
	int i, j, n = 4, m = 4;
	int a[4][4] = {{9, 2, 7 ,8},
		     {6, 4, 3, 7},
	     	     {5,8,1,8}, {7,6,9,4}};
//	cout << a[1][1];
	cout << calc(n -1, m, 0, a);
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {1, 5, 9, 2, 3}, k=16;
	int i, j, n=sizeof(a)/sizeof(a[0]);

	int tot = 1 << n, cnt =0;
	for(int mask = 0; mask < tot; mask++)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			if(mask & (1 << i))
			{
				sum += a[i];
			}
		}
		if(sum >= k)
		{
			cout << sum << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
}


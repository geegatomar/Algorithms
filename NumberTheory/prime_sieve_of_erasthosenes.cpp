#include<bits/stdc++.h>
using namespace std;
int i, j, n, m;

// fastest way of finding primes using SIEVE OF ERASTHOSENES
// Time complexity of this is O(N*loglogN) ~~ O(N)

int primes[1000005];      // will eventually have 1 for all the numbers that are not primes

void prime_sieve()
{
	for(int i = 2; i < 1005; i++)
	{
		if(primes[i] == 0)
		{
			for(int j = i*i; j < 1005; j += i)
				primes[j] = 1;
		}
	}

}

int main()
{
	int n;
	cin >> n;
	prime_sieve();
	for(int i = 0; i < n; i++)
	{
		if(primes[i] == 0)
			cout << i << endl;
	}
}

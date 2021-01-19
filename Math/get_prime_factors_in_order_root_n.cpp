map<int, int> get_prime_factorization(int n)
{
	map<int, int> mp;
	for(int i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			n /= i;
			mp[i]++;
		}
	}
	// Imp to specify this condition of (n > 1) for including this last prime factor
	if(n > 1)
		mp[n] = 1;
	return mp;
}


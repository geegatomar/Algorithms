#include<bits/stdc++.h>
using namespace std;

int main()
{
	double i, j, prob = 1;
	i = 0;
	while(prob > 0.5)
	{
		prob *= (365 - i)/365;
		i++;
	}
	cout << i << endl;
	
}

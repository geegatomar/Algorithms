#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &v)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return f(n-1, v) + abs(v[n-1] - v[n]);

        return min( f(n-1, v) + abs(v[n-1]-v[n]), f(n-2, v) + (abs(v[n-2]- v[n])));	
}

int main()
{
	int n = 6;
	vector<int> v{30, 10, 60, 10, 60, 50};                     
	vector<int> dp(n, 0);
	cout << f(n-1, v) << endl;

}


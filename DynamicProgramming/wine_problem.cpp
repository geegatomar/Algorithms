#include<bits/stdc++.h>
using namespace std;

int f(int l, int r, int n, vector<int> &v)
{
	int yr = n - (r - l);
	if(l == r)
		return v[l] * yr;
	return max( f(l+1, r, n, v) + v[l]*yr, f(l, r-1, n, v) + v[r]*yr); 
}

int main()
{
	vector<int> v{2, 4, 6, 2, 5};
	int i, j, n = v.size();
	cout << f(0, n-1, n, v) << endl;
}



#include<bits/stdc++.h>
using namespace std;

int f(int l, int r, int yr, vector<int> &v)
{
	if(l == r)
		return v[l] * yr;
	return max( f(l+1, r, yr+1, v) + v[l]*yr, f(l, r-1, yr+1, v) + v[r]*yr); 
}

int main()
{
	vector<int> v{2, 4, 6, 2, 5};
	int i, j, n = v.size();
	cout << f(0, n-1, 1, v) << endl;
}



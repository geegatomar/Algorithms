#include<bits/stdc++.h>
using namespace std;

void sort(int n, vector<int> &arr)
{
	if(n <= 0)
		return;
	sort(n - 1, arr);
	int key = arr[n];
	int i = n-1;
	while(i >= 0 && key < arr[i])
	{
		arr[i + 1] = arr[i];
		i--;
	}
	
	arr[i + 1] = key;

}

int main()
{
	vector<int> arr{3, 4, 1, 9, 5, 2, 7};
	int n = arr.size();
	sort(n - 1, arr);
	for(auto e : arr)
		cout << e << " ";
	cout << endl;
}


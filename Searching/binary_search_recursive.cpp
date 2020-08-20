#include<bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, int ele, vector<int> arr)
{
	if(low > high)
		return -1;
	int mid = low + (high - low)/2;
	if(arr[mid] == ele)
		return mid;
	else if(arr[mid] < ele)
		return binarySearch(mid + 1, high, ele, arr);
	else return binarySearch(low, mid - 1, ele, arr);

}

int main()
{
	vector<int> arr{2,4,6,7,9,10,34,67,90};
	int i, j, ele = 4, n = arr.size();
	cin >> ele;
	cout << binarySearch(0, n-1, ele, arr) << endl; 
}


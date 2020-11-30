#include<bits/stdc++.h>
using namespace std;
 
// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

//typedef tree<int, null_type, less<int>, rb_tree_tag, 
//             tree_order_statistics_node_update> 
//    pbds;

//#define ll long long
#define int long long
typedef pair<int, int> pi;
#define all(x)   (x).begin(),(x).end()
#define pb       push_back
//const int M = 1e9 + 7;
const int M = 998244353;
#define PI 3.14159265358979
const int inf = 1e10,  inf2 = 1e5;
const int MM = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;
 
const int N = 1e6, logN = 20;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt, sum = 0, d;
string s;
vector<int> v;

int partition(int l, int r)
{
    
    int pindex = l, pivot = v[r];
    for(int i = l; i <= r-1; i++)
    {
        if(v[i] <= pivot)
            swap(v[pindex], v[i]), pindex++;
    }
    swap(v[r], v[pindex]);
    return pindex;
}

int qselect(int l, int r)
{
    if(l == r)
        return l;
    int pi = partition(l, r);
    
    if(pi == k-1)
        return pi;
    if(pi < k-1)
        return qselect(pi + 1, r);
    else
        return qselect(l, pi - 1);

}

int32_t main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  sal = 0, x, y, l, r;
    int  i, j, q, t;
    int mn = INT_MAX, mx = INT_MIN;
    
    cin >> n;
    v.resize(n);
    
    for(i = 0; i < n; i++)
        cin >> v[i];
    cin >> k;
    cout << qselect(0, n-1) << endl;
    for(auto e: v)
        cout << e << " ";
}

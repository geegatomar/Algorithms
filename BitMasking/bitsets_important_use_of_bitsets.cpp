#include<bits/stdc++.h>
using namespace std;

// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//#define ll long long
#define int long long
typedef pair<int, int> pi;
const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf M*1000-100
const int MM = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;

const int N = 1e5 + 1;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt, sum = 0;

int32_t main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("op2.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  sal = 0, ii, jj, x, y, l, r, a, b;
    int  i, p, j, q, t;
    int mn = INT_MAX, mx = INT_MIN;

    cin >> n;
    vector<int> v(n);
    for(i = 0; i < n; i++)
        cin >> v[i];
    bitset<20> dp;
    dp.set(0);
    for(int i = 0; i < n; i++)
    {
        cout << "Before analyzing " << v[i] << ", dp is : " << dp << endl;
        dp |= dp << v[i];
        cout << "After analyzing " << v[i] << ", dp is : " << dp << endl;
    }
    cout << dp.count();

}

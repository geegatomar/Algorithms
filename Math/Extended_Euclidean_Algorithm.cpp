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
 
const int N = 1e6 + 3, logN = 20;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, wt, sum = 0, K, t;


int gcd(int a, int b, int &x, int &y)
{
    cout << a << " " << b << endl;
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1*(a / b);

    return g;
}


void SOLVE()
{
    int a, b, x = 0, y = 1;
    cin >> a >> b;
    cout << gcd(a, b, x, y) << " " << x << " " << y;
}


int32_t main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int T = 1;
    //cin >> T;
    while(T--)
    {
        SOLVE();
    }

}

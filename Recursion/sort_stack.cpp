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

void insert_sorted(stack<int> &st, int ele)
{
    if(st.empty() || st.top() > ele)
    {
        st.push(ele);
        return;
    }
    int topnow = st.top(); st.pop();
    insert_sorted(st, ele);
    st.push(topnow);
}

void sort(stack<int> &st)
{
    if(st.empty())
        return;
    int topnow = st.top(); st.pop();
    sort(st);
    insert_sorted(st, topnow);
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
    stack<int> st;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        st.push(x);
    }
    cin >> x;
    sort(st);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
}

#include<bits/stdc++.h>
using namespace std;
 
// for pbds(policy based data structure)
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;     
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
//#define ll long long
#define int long long
int ceil(int a, int b)
{
    return (a + b - 1)/b;
}
#define all(x)   (x).begin(),(x).end()
typedef pair<int, int> pi;
typedef tuple<int, int, int> tii;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf 1e18
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9; 
const int N = 2e5 + 2;

vector<vector<pair<int, int>>> g;
int vis[100], D[100];


void dijkstra(int n, int src)
{
    for(int i = 1; i <= n; i++)
    {
        D[i] = inf;
    }
    D[src] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int u = cur.second, uwt = cur.first;
        for(auto nbr : g[u])
        {
            int v = nbr.first, uvw = nbr.second;
            if(D[v] > D[u] + uvw)
            {
                D[v] = D[u] + uvw;
                pq.push({D[v], v});
                
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << D[i] << " ";
    }
}

int d[10][10];

void floyd_warshall(int n)
{

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            d[i][j] = inf;
            d[j][i] = inf;
        }
        for(auto e : g[i])
        {
            int v = e.first, w = e.second;
            d[i][v] = w;
            d[v][i] = w;
        }
        d[i][i] = 0;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << d[i][j] << " ";
        cout << endl; 
    }
}

void SOLVE()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    
    for(int i = 0; i <  m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    floyd_warshall(n);   
}
    
    
 
int32_t main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  sal = 0, ii, jj,x, y, l, r;
    int  i, j, q;
    int mn = INT_MAX, mx = INT_MIN;
 
    
    int T = 1;
    //cin >> T;
    for(int I = 1; I <= T; I++)
    {
        //cout << "Case #" << I << ": ";
        SOLVE();
    }
}

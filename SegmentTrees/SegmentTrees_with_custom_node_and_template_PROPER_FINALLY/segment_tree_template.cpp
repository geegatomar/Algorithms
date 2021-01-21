#include <bits/stdc++.h>
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
    return (a + b - 1) / b;
}
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pi;
typedef tuple<int, int, int> tii;
//const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf 1e18
const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;
const int N = 2e5 + 2;

class Node
{
public:
    int sum = 0;
    Node()
    {
        sum = 0;
    }
    Node(int s)
    {
        sum = s;
    }
};
Node nomerge(0);

class segtree
{
    int n;
    vector<Node> t, lazy;

    Node merge(const Node &left, const Node &right)
    {
        return Node(left.sum + right.sum);
    }

    void build(int i, int tl, int tr, vector<int> &v)
    {
        if (tl == tr)
        {
            t[i] = Node(v[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * i, tl, tm, v);
        build(2 * i + 1, tm + 1, tr, v);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }

    void push(int i)
    {
        t[2 * i].sum += lazy[i].sum;
        lazy[2 * i].sum += lazy[i].sum;
        t[2 * i + 1].sum += lazy[i].sum;
        lazy[2 * i + 1].sum += lazy[i].sum;
        lazy[i].sum = 0;
    }

    Node query(int i, int tl, int tr, int l, int r)
    {
        if (l > r)
            return nomerge;
        if (tl >= l && tr <= r)
            return t[i];
        push(i);
        int tm = (tl + tr) / 2;
        return merge(query(2 * i, tl, tm, l, min(tm, r)),
                     query(2 * i + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    //POINT ASSIGN
    void update(int i, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
        {
            t[i] = Node(new_val);
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * i, tl, tm, pos, new_val);
            else
                update(2 * i + 1, tm + 1, tr, pos, new_val);
            t[i] = merge(t[2 * i], t[2 * i + 1]);
        }
    }

    // RANGE UPDATE
    void update(int i, int tl, int tr, int l, int r, int addend)
    {
        if (l > r)
            return;

        if (tl == l && tr == r)
        {
            t[i].sum += addend;
            lazy[i].sum += addend;
        }
        else
        {
            push(i);
            int tm = (tl + tr) / 2;
            update(2 * i, tl, tm, l, min(tm, r), addend);
            update(2 * i + 1, tm + 1, tr, max(tm + 1, l), r, addend);
            t[i] = merge(t[2 * i], t[2 * i + 1]);
        }
    }

public:
    segtree(vector<int> v, int n)
    {
        this->n = n;
        t.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        build(1, 1, n, v);
    }

    Node query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }

    // point assign
    void update(int pos, int new_val)
    {
        update(1, 1, n, pos, new_val);
    }

    // range update
    void update(int l, int r, int addend)
    {
        update(1, 1, n, l, r, addend);
    }
};

void SOLVE()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    segtree sgtr(v, n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {

            int a, b, u;
            cin >> a >> b >> u;
            sgtr.update(a, b, u);
        }
        else
        {
            int k;
            cin >> k;
            cout << sgtr.query(k, k).sum << "\n";
        }
    }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sal = 0, ii, jj, x, y, l, r;
    int i, j, q;
    int mn = INT_MAX, mx = INT_MIN;

    int T = 1;
    //cin >> T;
    for (int I = 1; I <= T; I++)
    {
        //cout << "Case #" << I << ": ";
        SOLVE();
    }
}
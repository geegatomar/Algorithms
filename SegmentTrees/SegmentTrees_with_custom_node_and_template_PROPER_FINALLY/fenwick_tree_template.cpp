#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;

vector<int> bit(N);
int n, q;

void update(int i, int x)
{
    for (; i <= n; i += (i & -i))
    {
        bit[i] += x;
    }
}

int query(int i)
{
    int sum = 0;
    for (; i >= 1; i -= (i & -i))
    {
        sum += bit[i];
    }
    return sum;
}

int32_t main()
{
    cin >> n >> q;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        update(i, v[i]);
    }

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            int pos = l, new_val = r;
            int cur = query(l) - query(l - 1);
            update(l, new_val - cur);
        }
        else
            cout << query(r) - query(l - 1) << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

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
    vector<Node> t;
    vector<Node> l, merged;

    // MERGE
    Node merge(const Node &left, const Node &right)
    {
        return Node(left.sum + right.sum);
    }

    // BUILD
    void build(vector<int> a, int i, int tl, int tr)
    {
        if (tl == tr)
        {
            t[i] = Node(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * i, tl, tm);
        build(a, 2 * i + 1, tm + 1, tr);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }

public:
    // CONSTRUCTOR
    segtree(vector<int> a, int n)
    {
        this->n = n;
        t.resize(4 * n + 1);
        //l.resize(4*n + 1, nomerge);
        build(a, 1, 1, n);
    }

    void update(int l, int r, int new_val)
    {
        update(1, 1, n, l, r, new_val);
    }

    int query(int l, int r)
    {
        return query(1, 1, n, l, r).sum;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    segtree sgtr(a, n);
    sgtr.query(2, 4);
    sgtr.update(1, 3, 100);
    sgtr.query(2, 4);
}
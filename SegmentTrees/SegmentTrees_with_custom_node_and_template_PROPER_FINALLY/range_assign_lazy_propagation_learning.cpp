// Note: Segment trees are 1 indexed, so be careful

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int mx, freq;

    Node()
    {
        mx = 0;
        freq = 0;
    }
    Node(int s)
    {
        mx = s;
        freq = 1;
    }
};
Node nomerge(-1000000);

class segtree
{
    int n;
    vector<Node> t;
    vector<Node> l, marked;

    // MERGE
    Node merge(const Node &left, const Node &right)
    {
        //return Node(left.sum + right.sum);
        if (left.mx > right.mx)
        {
            return left;
        }
        else if (right.mx > left.mx)
        {
            return right;
        }
        Node tmp;
        tmp.mx = left.mx;
        tmp.freq = left.freq + right.freq;
        return tmp;
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

    // PUSH
    // This push (for lazy propagation) depends on if we do "range assign" or "range update"
    void push(int i)
    {
        if (marked[i])
        {
            t[i * 2] = t[i * 2 + 1] = t[i];
            marked[i] = false;
            marked[2 * i] = marked[2 * i + 1] = true;
        }
    }

    // QUERY
    Node query(int i, int tl, int tr, int l, int r)
    {
        if (l > r)
            return nomerge;
        if (tl == l && tr == r)
            return t[i];
        push(i);
        int tm = (tl + tr) / 2;
        return merge(query(2 * i, tl, tm, l, min(tm, r)),
                     query(2 * i + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    // ASSIGN UPDATES ( = )
    void update(int i, int tl, int tr, int l, int r, int new_val)
    {
        if (l > r)
            return;
        if (tl == l && r == tr)
        {
            t[i].sum = new_val;
            marked = true;
        }
        else
        {
            push(i);
            int tm = (tr + tl) / 2;
            update(2 * i, tl, tm, l, min(r, tm), new_val);
            update(2 * i + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
            //t[i] = merge(t[2 * i], t[2 * i + 1]);
            // note: if not using lazy prop, the updates of the leaf's need to be propagated upwards
        }
    }

public:
    // CONSTRUCTOR
    segtree(vector<int> a, int n)
    {
        this->n = n;
        t.resize(4 * n + 1);
        l.resize(4 * n + 1, nomerge);
        marked.resize(4 * n + 1, 0);
        build(a, 1, 1, n);
    }

    // range update
    void update(int l, int r, int add_val)
    {
        update(1, 1, n, l, r, add_val);
    }

    // point update
    void update(int pos, int add_val)
    {
        update(1, 1, n, pos, pos, add_val);
    }

    // range query
    int query(int l, int r)
    {
        Node ans = query(1, 1, n, l, r);
        return ans.mx;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
    }
    segtree sgtr(v, n);
    cout << sgtr.query(2, 4) << endl;
    //sgtr.update(1, 3, 100);
    cout << sgtr.query(1, 3) << endl;
    cout << sgtr.query(1, 5) << endl
         << sgtr.query(3, 3) << endl;
}
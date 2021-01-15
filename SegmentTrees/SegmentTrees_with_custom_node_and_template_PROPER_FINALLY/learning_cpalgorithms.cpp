// In segment trees, while creating the node and the merge function, alsways think
// about 'if i know the value for my left and right child' how will i combine them
// to get value for me (my current node)

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    // each node stores the answer for a range
    // the "answer" that we need is the one that we define as the attributes for this Node class
    int mx;
    Node() // just a constructor
    {
        mx = 0;
    }
    Node(int mx)
    {
        mx = mx;
    }
};
// IDENTITY NOMERGE
Node nomerge(0); // the one that causes no effect on merging with anyone else
// example if were finding maximums, we would want the nomerge to return -INF object

class segtree
{
    int n;
    vector<Node> t; // for the tree
    vector<Node> l; // for the lazy part
    vector<bool> marked;

    // CUSTOM MERGE
    Node merge(const Node &left, const Node &right) // to customize this merge function depending on question
    {
        if (left.mx >)
    }

    // QUERY
    Node query(int ind, int tl, int tr, int l, int r)
    {
        if (l > r)
            return nomerge;
        if (l == tl && r == tr)
            return t[ind];
        //push(ind);
        int mid = (tl + tr) / 2;
        return merge(query(2 * ind, tl, mid, l, min(r, mid)), query(2 * ind + 1, mid + 1, tr, max(mid + 1, l), r));
    }

    // UPDATE
    void update(int ind, int tl, int tr, int l, int r, int new_val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            // assign to the Node object according to the questions
            t[ind] = new_val;
        }
        else
        {
            int mid = tl + (tr - tl) / 2;
            update(2 * ind, tl, mid, l, min(r, mid), new_val);
            update(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r, new_val);
            t[ind] = merge(t[ind * 2], t[ind * 2 + 1]);
        }
    }

    // BUILD
    void build(vector<int> &a, int ind, int tl, int tr)
    {
        if (tr == tl)
        {
            t[ind] = Node(a[tl]);
            return;
        }
        int mid = tl + (tr - tl) / 2;
        build(a, 2 * ind, tl, mid);
        build(a, 2 * ind + 1, mid + 1, tr);
        t[ind] = merge(t[2 * ind], t[2 * ind + 1]);
    }

public:
    // these are all the public functions which I'll call on my segtree
    segtree(vector<int> a, int n) // the constructor
    {
        this->n = n;
        t.resize(4 * n + 1);
        l.resize(4 * n + 1, nomerge);
        marked.resize(4 * n + 1, 0);
        build(a, 1, 1, n);
    }

    Node query(int l, int r)
    {
        // calls the internal query function
        return query(1, 1, n, l, r);
    }

    void update(int l, int r, int val)
    {
        update(1, 1, n, l, r, val);
    }
};

int main()
{
}
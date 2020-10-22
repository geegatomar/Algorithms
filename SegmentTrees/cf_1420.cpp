#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+1;
#define ll long long
ll v[N];
 
class data
{
        public:
 
        ll pp, pm, mp, mm;
        data()
        {
                data (0, 0, 0, 0);
        }
        data(ll pp, ll pm, ll mp, ll mm)
        {
                this->pp = pp;
                this->pm = pm;
                this->mp = mp;
                this->mm = mm;
        }
};
 
data tree[4*N + 1];
 
data make_data(ll val)
{
        return data (val, 0, 0, -val);
}
 
data combine(data l, data r)
{
        data res;
        res.pp = max(l.pp + r.mp, l.pm + r.pp);
        res.pm = max(l.pp + r.mm, l.pm + r.pm);
        res.mp = max(l.mp + r.mp, l.mm + r.pp);
        res.mm = max(l.mp + r.mm, l.mm + r.pm);
        return res;
}
 
void build(ll node, ll s, ll e)
{
        if(s == e)
        {
                tree[node] = make_data(v[s]);
                return;
        }
        ll mid = s + (e - s)/2;
        build(2*node, s, mid);
        build(2*node + 1, mid + 1, e);
        tree[node] = combine(tree[2*node], tree[2*node + 1]);
}
 
void update(ll node, ll s, ll e, ll pos, ll val)         // point update (assignment)
{
        if(pos > e || pos < s)
                return;
        if(s == e && pos == s)
        {
                tree[node] = make_data(val);
                return;
        }
        ll mid = s + (e - s)/2;
        if(pos <= mid)
            update(2*node, s, mid, pos, val);
        else
            update(2*node + 1, mid + 1, e, pos, val);
        tree[node] = combine(tree[2*node], tree[2*node + 1]);
}
 
 
int main()
{
 
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("op2.txt", "w", stdout);
    #endif
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
 
        while(t--)
        {
        ll i, j, n, q;
        cin >> n >> q;
        for(i = 1; i <= n; i++)
        {
                cin >> v[i];
        }
        build(1, 1, n);
 
        for(i = 0; i < q + 1; i++)
        {
                //data ans = query(1, 1, n, 1, n);
                data ans = tree[1];
                cout << max({ans.pp, ans.pm, ans.mp, ans.mm}) << "\n";
 
                if(i == q)
                        break;
 
                ll l, r;
                cin >> l >> r;
                update(1, 1, n, l, v[r]);
                update(1, 1, n, r, v[l]);
                swap(v[l], v[r]);
 
        }
        }
}

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
//typedef pair<int, int> pi;
const int M = 1e9 + 7;
#define PI 3.14159265358979
#define inf 1e15
//const int M = 998244353;
const int lim = 3e6 + 5, lim2 = 1e9;
 
const int N = 2e5 + 2;
int n = 7, m, k, dots = 0, cou = 0, yes = 0, r, w, p;


struct Trie{
	Trie* children[26] = {NULL};
	int cnt = 0;                  // count of active words in subtree of this node

};


int ans = 0;

void insert(Trie *root, string word)
{
	Trie* cur = root;
	for(auto ch : word)
	{
		if(!cur->children[ch - 'A'])
			cur->children[ch - 'A'] = new Trie();
		cur = cur->children[ch - 'A'];
	}
	cur->cnt++;
}


void dfs(Trie *cur, int lvl, int &k)
{
	for(auto ch = 0; ch <= 25; ch++)
	{
		if(cur->children[ch])
		{
			dfs(cur->children[ch], lvl + 1, k);
			cur->cnt += (cur->children[ch])->cnt;
		}
	}
	while(cur->cnt >= k)
	{
		cur->cnt -= k;
		ans += lvl;
	}
}

 
void SOLVE()
{
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	Trie *root = new Trie();

	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		insert(root, v[i]);
	}
	ans = 0;
	dfs(root, 0, k);
	cout << ans << "\n";
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
	cin >> T;
	for(int I = 1; I <= T; I++)
	{
		cout << "Case #" << I << ": ";
		SOLVE();
	}
}

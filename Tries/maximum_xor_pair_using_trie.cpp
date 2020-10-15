#include<bits/stdc++.h>
using namespace std;

// this trie implementation is slightly different from the ones you did so far(all the strings one)
// Here, you have only 0s and 1s in the i/p string. So one implementation could be to go leftchild on getting 0 and go right child on i/p 1.

struct Trie
{
	Trie *left;
	Trie *right;

	Trie()
	{
		left = NULL;
		right = NULL;
	}
};

struct Trie *root;
vector<int> v;

void insert(int n)         // the number n is given as is, we shall now do bit manipulation
{
	Trie *curr = root;
	for(int i = 31; i >= 0; i--)
	{
		int b = (n >> i) & 1;                         // checking if ith bit is set
	        if(b == 0)
		{
			if(!curr->left)
				curr->left = new Trie();
			curr = curr->left;
		}	
		else
		{
			if(!curr->right)
				curr->right = new Trie();
			curr = curr->right;
		}
	}
}

int findmax(int n)
{
	Trie *curr = root;
	int ans = 0;
	for(int i = 31; i >= 0; i--)
	{
		int b = (n >> i) & 1;
		if(b == 1)                 // we want max xor, so if this bit is 1,we'll try to look for 0
		{
			if(curr->left)
			{
				ans += (1 << i);
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
		else
		{
			if(curr->right)
			{
				ans += (1 << i);
				curr = curr->right;
			}
			else
				curr = curr->left;
		}
	}
	return ans;
}

int findMaxXorPair(int n)        // n is size of v
{
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		mx = max(mx, findmax(v[i]));
	}
	return mx;
}

int main()
{
	root = new Trie();
	int i, n;
	cin >> n;
	v.resize(n);
	for(i = 0; i < n; i++)
	{
		cin >> v[i];
		insert(v[i]);
	}
	cout << findMaxXorPair(n) << endl;

}

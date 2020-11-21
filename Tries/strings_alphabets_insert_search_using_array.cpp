#include<bits/stdc++.h>
using namespace std;
#define SIZ 26

// When strings are given, prefer this approach (over the map approach)

struct trie
{
	struct trie* children[SIZ];
	bool is_endofword;
};

struct trie *root = new trie();

void insert(string s)
{
	trie *curr = root;                                   // start building each tree at the root node
	for(int i = 0; i < s.size(); i++)
	{
		if(!curr -> children[s[i] - 'a'])
			curr -> children[s[i] - 'a'] = new trie();
		curr = curr -> children[s[i] - 'a'];
	}
	curr -> is_endofword = true;
}

bool search(string s)
{
	trie *curr = root;
	for(int i = 0; i < s.size(); i++)
	{
		if(!curr -> children[s[i] - 'a'])
			return false;
		curr = curr -> children[s[i] - 'a'];
	}
	return (curr != NULL && curr -> is_endofword);
}

int main()
{
	int i, j, n, m;
	cout << "How many strings? ";
	cin >> n;
	vector<string> keys(n);
	for(i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		keys[i] = s;
		insert(s);
	}

	cout << "Enter string to find ? ";
	string s;
	cin >> s;
	cout << search(s) << endl;
}

#include<bits/stdc++.h>
using namespace std;

struct Trie
{
	map<char, Trie*> children;
	bool isend;

	Trie()
	{
		isend = false;
	}
};

struct Trie *root;

void insert(string word)
{
	Trie *curr = root;

	for(char ch: word)
	{
		if(!curr->children.count(ch))
			curr->children[ch] = new Trie();
		curr = curr->children[ch];
	}
	curr->isend = true;
}

bool search(string word)
{
	Trie *curr = root;

	for(char ch: word)
	{
		if(!curr->children.count(ch))
			return false;
		curr = curr->children[ch];
	}
	return curr->isend == true;
}

int main()
{
	root = new Trie();
	insert("abab");
	insert("abaccbs");
	insert("abb");
	cout << "Searching ab: " << search("ab") << endl;
	cout << "Searching abab: " << search("abab") << endl;
}

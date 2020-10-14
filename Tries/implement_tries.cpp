#include<bits/stdc++.h>
using namespace std;

class Trie
{
	map<char, Trie*> children;
	bool isEndOfWord = false;

	Trie() {}

	void insert(string word)
	{
		Trie *node = this;
		for(char ch: word)
		{
			if(!node->children.count(ch))
				node->children[ch] = new Trie();
			node = node->chidren[ch];
		}
		node -> isEndOfWord = true;
	}

	bool search(string word)
	{
		Trie *node = this;
		for(char ch: word)
		{
			if(!node->children.count(ch))
				node->children[ch] = new Trie();
			node = node->children[ch];
		}
		node -> isEndOfWord == true;
	}
};

int main()
{
}

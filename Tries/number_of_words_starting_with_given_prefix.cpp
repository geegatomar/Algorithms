#include<bits/stdc++.h>
using namespace std;

struct Trie
{
	map<char, Trie*> children;
	bool isend;
	int cnt;

	Trie()
	{
		isend = false;
		cnt = 0;
	}
};

struct Trie *root;

void insert(string word)
{
	Trie *curr = root;
	
	for(char ch : word)
	{
		if(!curr->children.count(ch))
			curr->children[ch] = new Trie();
		curr->cnt++;
		curr = curr->children[ch];
	}
	curr->cnt++;
	curr->isend = true;
}

int search(string prefix)
{
	Trie *curr = root;

	for(char ch: prefix)
	{
		if(!curr->children.count(ch))
			return 0;
		curr = curr->children[ch];
	}
	return curr->cnt;
}

void rremove(string word)
{
	Trie *curr = root;
	for(char ch: word)
	{
		curr->cnt--;
		curr = curr->children[ch];
	}
	curr->cnt--;
	curr->isend = false;
}

int main()
{
	root = new Trie();
	insert("abaabs");
	insert("abababbb");
	insert("bbbabab");
	insert("aba");
	cout << "Number of words with prefix 'ab' : " << search("ab") << endl;
	insert("abbb");
	insert("abash");
	cout << "Number of words with prefix 'aba' : " << search("aba") << endl;
        cout << "Deletig/Removing : aba and abaabs " << endl;
	rremove("aba");
	rremove("abaabs");
	cout << "Number of words with prefix 'ab' : " << search("ab") << endl;
        cout << "Number of words with prefix 'aba' : " << search("aba") << endl;

}

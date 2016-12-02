#pragma once
#include <string>
#include "Node.h"

class Trie {
public:
	Trie();
	~Trie();
	bool insertWord(std::string word);
	bool containsWord(std::string word);
private:
	Node *root;
};
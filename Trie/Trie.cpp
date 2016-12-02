#include "Trie.h"

Trie::Trie() {
	this->root = new Node('\0');
}

Trie::~Trie() {
	delete this->root;
}

bool Trie::insertWord(std::string word) {
	if (word.empty()) return false;

	Node *parent = this->root;
	bool inserted = false;
	for (unsigned int i = 0; i < word.length(); i++) {
		Node *childToInsert = new Node(word.at(i));
		bool newChildCreated = parent->addChild(childToInsert);
		if (newChildCreated){
			inserted = true;
			parent = childToInsert;
		}
		else {
			delete childToInsert;
			parent = parent->getChild(word.at(i));
		}
	}
	parent->setIsCompleteWord();

	return inserted;
}

bool Trie::containsWord(std::string word) {
	Node *current = this->root;

	for (char c : word) {
		current = current->getChild(c);
		if (current == nullptr) return false;
	}
	return current->getIsCompleteWord();
}
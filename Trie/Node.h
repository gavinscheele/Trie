#pragma once
#include <unordered_map>
#include <iostream>

class Node {
public:
	Node(char data);
	~Node();
	bool getIsCompleteWord();
	void setIsCompleteWord();
	bool addChild(Node *);
	Node* getChild(char key);
	char getData();

private:
	std::unordered_map<char, Node*> *children;
	bool isCompleteWord;
	char data;
};
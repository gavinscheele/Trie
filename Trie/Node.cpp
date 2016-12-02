#include "Node.h"

Node::Node(char data) {
	this->data = data;
	this->isCompleteWord = false;
	this->children = new std::unordered_map<char, Node*>();
}

Node::~Node() {
	for (auto it = (*this->children).begin(); it != (*this->children).end(); it++) {
		delete it->second;
	}
	delete this->children;
}

bool Node::getIsCompleteWord() {
	return this->isCompleteWord;
}

void Node::setIsCompleteWord() {
	this->isCompleteWord = true;
}

bool Node::addChild(Node *child) {
	if (this->children->find(child->getData()) == (*this->children).end()) {
		this->children->insert(std::make_pair(child->getData(), child));
		return true;
	}
	return false;
}

Node* Node::getChild(char key) {
	Node *result;
	try {
		result = this->children->at(key);
	}
	catch (std::out_of_range) {
		return nullptr;
	}
	return result;
}

char Node::getData() {
	return this->data;
}
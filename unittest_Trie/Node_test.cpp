#include "stdafx.h"
#include "gtest/gtest.h"
#include "Node.h"

class NodeTest : public ::testing::Test {
public:
	Node *a;
	Node *b;

	NodeTest() {
	}

	void SetUp() {
		a = new Node('a');
		b = new Node('b');
	}

	void TearDown() {
		delete a;
		delete b;
	}

	~NodeTest() {

	}

};

TEST_F(NodeTest, constructor)
{
	EXPECT_NE(a, nullptr);
	EXPECT_EQ(a->getData(), 'a');
	EXPECT_EQ(a->getIsCompleteWord(), false);
	try {
		Node *result = a->getChild('b');
		EXPECT_EQ(result, nullptr);
	}
	catch (...) {
		FAIL() << "Out of range exception not thrown.";
	}
}

TEST_F(NodeTest, nullData) {
	Node *nullNode = new Node('\0');
	EXPECT_EQ(nullNode->getData(), NULL);
}

TEST_F(NodeTest, getSetIsCompleteWord) {
	EXPECT_FALSE(a->getIsCompleteWord());
	a->setIsCompleteWord();
	EXPECT_TRUE(a->getIsCompleteWord());
}

TEST_F(NodeTest, addChild) {
	Node *b = new Node('b');
	a->addChild(b);
	EXPECT_EQ(a->getChild('b'), b);
}

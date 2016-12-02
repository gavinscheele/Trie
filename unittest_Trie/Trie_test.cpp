#include "stdafx.h"
#include "gtest/gtest.h"
#include "Trie.h"

class TrieTest : public ::testing::Test {
public:
	Trie *trie;

	TrieTest() {
		trie = new Trie();
	}

	void SetUp() {
	}

	void TearDown() {
		delete trie;
		
	}

	~TrieTest() {

	}

};

TEST_F(TrieTest, constructor)
{
	EXPECT_NE(trie, nullptr);
}

TEST_F(TrieTest, insertEmptyWord) {
	EXPECT_FALSE(trie->insertWord(""));

}

TEST_F(TrieTest, insertNormalWord) {
	EXPECT_TRUE(trie->insertWord("word"));
}

TEST_F(TrieTest, insertShortWord) {
	EXPECT_TRUE(trie->insertWord("z"));
}

TEST_F(TrieTest, insertLongWord) {
	EXPECT_TRUE(trie->insertWord("Praesent sapien massa, convallis a pellentesque nec, egestas non nisi. Curabitur aliquet quam id dui posuere blandit. Nulla porttitor accumsan tincidunt. Curabitur aliquet quam id dui posuere blandit. Vivamus suscipit tortor eget felis porttitor volutpat. Donec rutrum congue leo eget malesuada. Nulla porttitor accumsan tincidunt. Vivamus suscipit tortor eget felis porttitor volutpat. Donec rutrum congue leo eget malesuada. Sed porttitor lectus nibh."));
}

TEST_F(TrieTest, insertSpecialCharacters) {
	EXPECT_TRUE(trie->insertWord("*&^%$#@!()-_=+{}[]\\|'\";:.>,</?~`"));
}

TEST_F(TrieTest, containsWordNormal) {
	trie->insertWord("cat");
	EXPECT_TRUE(trie->containsWord("cat"));
}

TEST_F(TrieTest, containsShortWord) {
	trie->insertWord("a");
	EXPECT_TRUE(trie->containsWord("a"));
}

TEST_F(TrieTest, containsLongWord) {
	trie->insertWord("asdfl;kajsdf;lkasjdflkasdl;fkjasdlfkjas;dlkfjas;ldgfdngwearvouisepghvsdfujhnsdfg");
	EXPECT_TRUE(trie->containsWord("asdfl;kajsdf;lkasjdflkasdl;fkjasdlfkjas;dlkfjas;ldgfdngwearvouisepghvsdfujhnsdfg"));
}

TEST_F(TrieTest, containsInvalidShortWord) {
	trie->insertWord("a");
	EXPECT_FALSE(trie->containsWord("b"));
}

TEST_F(TrieTest, containsInvalidNormalWord) {
	trie->insertWord("cat");
	EXPECT_FALSE(trie->containsWord("dog"));
}

TEST_F(TrieTest, containsInvalidSubstring) {
	trie->insertWord("tops");
	EXPECT_FALSE(trie->containsWord("top"));
}

TEST_F(TrieTest, containsLongerWord) {
	trie->insertWord("a");
	EXPECT_FALSE(trie->containsWord("longerword"));
}

TEST_F(TrieTest, containsEmpty) {
	trie->insertWord("abc");
	EXPECT_FALSE(trie->containsWord(""));
}

TEST_F(TrieTest, containsCaseSensitive) {
	trie->insertWord("a");
	EXPECT_FALSE(trie->containsWord("A"));

	trie->insertWord("B");
	EXPECT_FALSE(trie->containsWord("b"));
}

TEST_F(TrieTest, insertWithCommonPrefix) {
	trie->insertWord("top");
	trie->insertWord("tops");
	trie->insertWord("topper");
	trie->insertWord("toppings");
	EXPECT_TRUE(trie->containsWord("top"));
	EXPECT_TRUE(trie->containsWord("tops"));
	EXPECT_TRUE(trie->containsWord("topper"));
	EXPECT_TRUE(trie->containsWord("toppings"));
	EXPECT_FALSE(trie->containsWord("to"));
	EXPECT_FALSE(trie->containsWord("topping"));
}

TEST_F(TrieTest, insertWordWithCommonSuffix) {
	trie->insertWord("bat");
	trie->insertWord("hat");
	trie->insertWord("cat");
	EXPECT_TRUE(trie->containsWord("bat"));
	EXPECT_TRUE(trie->containsWord("hat"));
	EXPECT_TRUE(trie->containsWord("cat"));
	EXPECT_FALSE(trie->containsWord("at"));
	EXPECT_FALSE(trie->containsWord("atbat"));
	EXPECT_FALSE(trie->containsWord("somehat"));
	EXPECT_FALSE(trie->containsWord("acat"));
}

TEST_F(TrieTest, wideTree) {
	char asciiCharacter = 'a';
	for (int i = 0; i < 256; i++,asciiCharacter++) {
		trie->insertWord(std::string(1, asciiCharacter));
	}

	asciiCharacter = 'a';
	for (int i = 0; i < 256; i++,asciiCharacter++) {
		EXPECT_TRUE(trie->containsWord(std::string(1, asciiCharacter)));
	}
	
}

TEST_F(TrieTest, insertDuplicate) {
	trie->insertWord("testword");
	EXPECT_FALSE(trie->insertWord("testword"));
}

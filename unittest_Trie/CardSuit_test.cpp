#include "stdafx.h"
#include "gtest/gtest.h"
#include "CardSuit.h"
#include "Constants.h"

class CardSuitTest : public ::testing::Test {
public:
	CardSuit *club;
	CardSuit *secondClub;
	CardSuit *diamond;
	CardSuit *heart;
	CardSuit *spade;

	CardSuitTest() {
		club = new CardSuit(CLUBS);
		secondClub = new CardSuit(CLUBS);
		diamond = new CardSuit(DIAMONDS);
		heart = new CardSuit(HEARTS);
		spade = new CardSuit(SPADES);
	}

	void SetUp() {
	}

	void TearDown() {
		delete club;
		delete secondClub;
		delete diamond;
		delete heart;
		delete spade;
	}

	~CardSuitTest() {
	}

};

TEST_F(CardSuitTest, getDisplayValue)
{
	EXPECT_EQ(CLUBS_STR, club->getDisplayValue());
	EXPECT_EQ(DIAMONDS_STR, diamond->getDisplayValue());
	EXPECT_EQ(HEARTS_STR, heart->getDisplayValue());
	EXPECT_EQ(SPADES_STR, spade->getDisplayValue());
}

TEST_F(CardSuitTest, lessThan)
{
	EXPECT_TRUE(*club < *diamond);
	EXPECT_TRUE(*diamond < *heart);
	EXPECT_TRUE(*heart < *spade);
	EXPECT_FALSE(*spade < *club);
}

TEST_F(CardSuitTest, greaterThan)
{
	EXPECT_TRUE(*spade > *heart);
	EXPECT_TRUE(*heart > *diamond);
	EXPECT_TRUE(*diamond > *club);
	EXPECT_FALSE(*club > *spade);
}

TEST_F(CardSuitTest, equal)
{
	EXPECT_TRUE(*club == *club);
	EXPECT_TRUE(*club == *secondClub);
}

TEST_F(CardSuitTest, invalidSuit)
{
	try {
		CardSuit *c = new CardSuit(-1);
		FAIL();
	}
	catch (runtime_error &e) {
		ASSERT_STREQ(e.what(), "Invalid suit");
	}

	try {
		CardSuit *c = new CardSuit(0);
		FAIL();
	}
	catch (runtime_error &e) {
		ASSERT_STREQ(e.what(), "Invalid suit");
	}

	try {
		CardSuit *c = new CardSuit(-1);
		FAIL();
	}
	catch (runtime_error &e) {
		ASSERT_STREQ(e.what(), "Invalid suit");
	}
}
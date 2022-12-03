/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test) {
	ASSERT_EQ(true,true);
}

//LENGTH_DIFFERENCE TESTS

TEST(tappityTest, length_difference_small_zero) {
	std::string ref = "THIS";
	tappity tap = tappity(ref);
	tap.entry(ref);
	ASSERT_EQ(tap.length_difference(), 0);
}

TEST(tappityTest, length_difference_small) {
	std::string user_input = "THIS";
	std::string ref_phrase = "";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.length_difference(), 4);
}

TEST(tappityTest, length_difference_positive) {
	std::string user_input = "";
	std::string ref_phrase = "THIS";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.length_difference(), 4);
}

TEST(tappityTest, length_difference_one) {
	std::string user_input = "THI";
	std::string ref_phrase = "THIS";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.length_difference(), 1);
}

TEST(tappityTest, length_difference_empty) {
	std::string ref_phrase = "";
	tappity tap = tappity(ref_phrase);
	ASSERT_EQ(tap.length_difference(), 0);
}

//ACCURACY TESTS 

TEST(tappityTest, accuracy_zero) {
	std::string user_input = "";
	std::string ref_phrase = "THIS";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 0);
}

TEST(tappityTest, accuracy_100) {
	std::string user_input = "THIS";
	std::string ref_phrase = "THIS";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 100);
}

TEST(tappityTest, accuracy_25_under) {
	std::string user_input = "T";
	std::string ref_phrase = "THIS";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 25);
}

TEST(tappityTest, accuracy_25_over) {
	std::string user_input = "TAAAAAA";
	std::string ref_phrase = "THIS";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 25);
}

TEST(tappityTest, accuracy_33_under) {
	std::string user_input = "T";
	std::string ref_phrase = "THI";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 100*(1.0/3.0));
}

TEST(tappityTest, accuracy_33_over) {
	std::string user_input = "TPPPPPPP";
	std::string ref_phrase = "THI";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 100*(1.0/3.0));
}

TEST(tappityTest, accuracy_100_lower_upper) {
	std::string user_input = "This Is A Test";
	std::string ref_phrase = "This Is A Test";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 100);
}

TEST(tappityTest, accuracy_lower_upper) {
	std::string user_input = "this is a test";
	std::string ref_phrase = "This Is A Test";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 100*(10.0/14.0));
}

TEST(tappityTest, accuracy_0_lower_upper) {
	std::string user_input = "TTTTTTTTTTT";
	std::string ref_phrase = "ttttttttttt";
	tappity tap = tappity(ref_phrase);
	tap.entry(user_input);
	ASSERT_EQ(tap.accuracy(), 0);
}
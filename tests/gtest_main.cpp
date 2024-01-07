#include <gtest/gtest.h>
#include <string>
#include <cmath>
#include "evalparser.hpp"

const float MAX_FLOAT_DIFFERENCE = 1e-9;  // Max value for equality of float inaccuracy

TEST(ArithmeticTest, BasicEquations)
{
	float addDiff = evaluate("3 + 2") - 5.f;
	float subtractDiff = evaluate("3 - 2") - 1.f;
	float multiplyDiff = evaluate("3 * 2") - 6.f;
	float divideDiff = evaluate("6 / 2") - 3.f;

	EXPECT_TRUE(std::abs(addDiff) < MAX_FLOAT_DIFFERENCE);
	EXPECT_TRUE(std::abs(subtractDiff) < MAX_FLOAT_DIFFERENCE);
	EXPECT_TRUE(std::abs(multiplyDiff) < MAX_FLOAT_DIFFERENCE);
	EXPECT_TRUE(std::abs(divideDiff) < MAX_FLOAT_DIFFERENCE);
}

TEST(ArithmeticTest, Precedence)
{
	float precedenceDiff = evaluate("3 - 2 + 5 * 3 / 2") - 8.5f;

	EXPECT_TRUE(std::abs(precedenceDiff) < MAX_FLOAT_DIFFERENCE);
}

TEST(AirthmeticTest, Parenthesis)
{
	float parenthesisDiff = evaluate("(3 * (5 - 3)) / 2 * (5 + 3)") - 24.f;
	EXPECT_TRUE(std::abs(parenthesisDiff) < MAX_FLOAT_DIFFERENCE); 
}

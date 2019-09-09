#include "pch.h"

#include "../LinkedStack/LinkedStack.hpp"


class LinkedStackTestFixture : public ::testing::Test
{
protected:
	LinkedStackTestFixture(){ }

	~LinkedStackTestFixture(){ }

	void SetUp() override
	{

	}

	void TearDown() override
	{

	}

	LinkedStack<int>	_linkedStack;

};



TEST_F(LinkedStackTestFixture, Constructor) {
	EXPECT_EQ(_linkedStack.isEmpty(), true);
	EXPECT_THROW(_linkedStack.pop(), std::underflow_error);
}


TEST_F(LinkedStackTestFixture, pushFunc) {
	_linkedStack.push(1);
	_linkedStack.push(2);
	EXPECT_EQ(_linkedStack.top(), 2);
	_linkedStack.pop();
	EXPECT_EQ(_linkedStack.top(), 1);
}

TEST_F(LinkedStackTestFixture, popFunc) {
	_linkedStack.push(1);
	EXPECT_EQ(_linkedStack.top(), 1);
	_linkedStack.pop();
	EXPECT_THROW(_linkedStack.top(), std::underflow_error);
}

TEST_F(LinkedStackTestFixture, topFunc) {
	_linkedStack.push(1);
	EXPECT_EQ(_linkedStack.top(), 1);
	_linkedStack.pop();
	EXPECT_THROW(_linkedStack.pop(), std::underflow_error);
}

TEST_F(LinkedStackTestFixture, isEmptyFunc) {
	EXPECT_EQ(_linkedStack.isEmpty(), true);
	_linkedStack.push(1);
	EXPECT_EQ(_linkedStack.isEmpty(), false);
	_linkedStack.pop();
	EXPECT_EQ(_linkedStack.isEmpty(), true);
}

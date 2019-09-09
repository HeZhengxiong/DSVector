#include "pch.h"

#include "../ArrayStack/ArrayStack.hpp"


class ArrayStackTestFixture : public ::testing::Test
{
protected:

	ArrayStackTestFixture() { }
	~ArrayStackTestFixture() { }

	void SetUp() override
	{

	}

	void TearDown() override
	{

	}

	ArrayStack<int>	_stack;
};



TEST_F(ArrayStackTestFixture, ConstructorTEST) {
	EXPECT_EQ(_stack.isEmpty(), true);
	EXPECT_EQ(_stack.isFull(), false);
	EXPECT_THROW(_stack.pop(), std::underflow_error);
}


TEST_F(ArrayStackTestFixture, pushTEST) {
	EXPECT_EQ(_stack.isEmpty(), true);
	int v1 = 1;
	int v2 = 2;
	_stack.push(v1);
	_stack.push(v2);
	EXPECT_EQ(_stack.top(), 2);
	_stack.pop();
	EXPECT_EQ(_stack.top(), 1);
}

TEST_F(ArrayStackTestFixture, pushToOverflowTEST) {
	for (int i = 0; i < 100; i++)
		_stack.push(i);
	EXPECT_EQ(_stack.isFull(), true);
	EXPECT_THROW(_stack.push(100), std::overflow_error);
}


TEST_F(ArrayStackTestFixture, pushRValueTEST) {
	EXPECT_EQ(_stack.isEmpty(), true);
	_stack.push(1);
	_stack.push(2);
	EXPECT_EQ(_stack.top(), 2);
	_stack.pop();
	EXPECT_EQ(_stack.top(), 1);
}


TEST_F(ArrayStackTestFixture, popTEST) {
	EXPECT_EQ(_stack.isEmpty(), true);
	EXPECT_THROW(_stack.pop(), std::underflow_error);
	_stack.push(10);
	_stack.push(9);
	_stack.pop();
	EXPECT_EQ(_stack.top(), 10);
}


TEST_F(ArrayStackTestFixture, topTEST) {
	EXPECT_EQ(_stack.isEmpty(), true);
	EXPECT_THROW(_stack.top(), std::underflow_error);
	_stack.push(10);
	_stack.push(9);
	_stack.pop();
	EXPECT_EQ(_stack.top(), 10);
}

#include "pch.h"

#include "../LinkedQueue/LinkedQueue.hpp"


class LinkedQueueTestFixture : public ::testing::Test
{
protected:
	LinkedQueueTestFixture()
	{

	}

	~LinkedQueueTestFixture()
	{

	}

	virtual void SetUp() override
	{

	}

	virtual void TearDown() override
	{

	}

	LinkedQueue<int>	_intQueue;
};



TEST_F(LinkedQueueTestFixture, LinkedQueueConstructor) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	EXPECT_THROW(_intQueue.dequeue(), std::underflow_error);
	EXPECT_THROW(_intQueue.front(), std::underflow_error);
	EXPECT_THROW(_intQueue.rear(), std::underflow_error);
}

TEST_F(LinkedQueueTestFixture, EnqueueFunction) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	_intQueue.enqueue(100);
	EXPECT_EQ(_intQueue.isEmpty(), false);
	EXPECT_EQ(_intQueue.front(), 100);
}

TEST_F(LinkedQueueTestFixture, DequeueFunction) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	_intQueue.enqueue(200);
	EXPECT_EQ(_intQueue.isEmpty(), false);
	_intQueue.dequeue();
	EXPECT_EQ(_intQueue.isEmpty(), true);
}

TEST_F(LinkedQueueTestFixture, rearFunction) {
	_intQueue.enqueue(100);
	_intQueue.enqueue(1);
	EXPECT_EQ(_intQueue.rear(), 1);
}

TEST_F(LinkedQueueTestFixture, frontFunction) {
	_intQueue.enqueue(100);
	_intQueue.enqueue(1);
	EXPECT_EQ(_intQueue.rear(), 1);
	EXPECT_EQ(_intQueue.front(), 100);
	_intQueue.dequeue();
	EXPECT_EQ(_intQueue.rear(), 1);
	EXPECT_EQ(_intQueue.front(), 1);
}

TEST_F(LinkedQueueTestFixture, isEmptyFunction) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	_intQueue.enqueue(1);
	EXPECT_EQ(_intQueue.isEmpty(), false);
	_intQueue.dequeue();
	EXPECT_EQ(_intQueue.isEmpty(), true);
}

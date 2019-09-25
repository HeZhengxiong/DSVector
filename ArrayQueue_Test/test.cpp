#include "pch.h"

#include "../ArrayQueue/ArrayQueue.hpp"


class ArrayQueueTestFixture : public ::testing::Test
{
protected:
	ArrayQueueTestFixture()
	{

	}

	~ArrayQueueTestFixture()
	{

	}

	virtual void SetUp() override
	{

	}

	virtual void TearDown() override
	{

	}

	ArrayQueue<int>	_intQueue;
};

#define NO_SIZE_IMPLEMENT

TEST_F(ArrayQueueTestFixture, ArrayQueueConstructor) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	EXPECT_THROW(_intQueue.dequeue(), std::underflow_error);
	EXPECT_THROW(_intQueue.front(), std::underflow_error);
	EXPECT_THROW(_intQueue.rear(), std::underflow_error);
}

TEST_F(ArrayQueueTestFixture, EnqueueFunction) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	_intQueue.enqueue(100);
	EXPECT_EQ(_intQueue.isEmpty(), false);
	EXPECT_EQ(_intQueue.front(), 100);
}

TEST_F(ArrayQueueTestFixture, DequeueFunction) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	_intQueue.enqueue(200);
	EXPECT_EQ(_intQueue.isEmpty(), false);
	_intQueue.dequeue();
	EXPECT_EQ(_intQueue.isEmpty(), true);
}

TEST_F(ArrayQueueTestFixture, rearFunction) {
	_intQueue.enqueue(100);
	_intQueue.enqueue(1);
	EXPECT_EQ(_intQueue.rear(), 1);
}

TEST_F(ArrayQueueTestFixture, frontFunction) {
	_intQueue.enqueue(100);
	_intQueue.enqueue(1);
	EXPECT_EQ(_intQueue.rear(), 1);
	EXPECT_EQ(_intQueue.front(), 100);
	_intQueue.dequeue();
	EXPECT_EQ(_intQueue.rear(), 1);
	EXPECT_EQ(_intQueue.front(), 1);
}

TEST_F(ArrayQueueTestFixture, isEmptyFunction) {
	EXPECT_EQ(_intQueue.isEmpty(), true);
	_intQueue.enqueue(1);
	EXPECT_EQ(_intQueue.isEmpty(), false);
	_intQueue.dequeue();
	EXPECT_EQ(_intQueue.isEmpty(), true);
}

TEST_F(ArrayQueueTestFixture, isFullFunction) {

#if defined NO_SIZE_IMPLEMENT

	for (int i = 1; i < 10; ++i)
		_intQueue.enqueue(i);
	EXPECT_EQ(_intQueue.isFull(), true);
	EXPECT_EQ(_intQueue.rear(), 9);
	EXPECT_EQ(_intQueue.front(), 1);

	for (int i = 0; i < 5; i++)
		_intQueue.dequeue();
	EXPECT_EQ(_intQueue.front(), 6);
	for (int i = 0; i < 4; i++)
		_intQueue.dequeue();
	EXPECT_EQ(_intQueue.isEmpty(), true);


#else

	for (int i = 1; i < 11; ++i)
		_intQueue.enqueue(i);
	EXPECT_EQ(_intQueue.isFull(), true);
	EXPECT_EQ(_intQueue.rear(), 10);
	EXPECT_EQ(_intQueue.front(), 1);

	for (int i = 0; i < 5; i++)
		_intQueue.dequeue();
	EXPECT_EQ(_intQueue.front(), 6);
	for (int i = 0; i < 5; i++)
		_intQueue.dequeue();
	EXPECT_EQ(_intQueue.isEmpty(), true);


#endif


}

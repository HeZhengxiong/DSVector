#include "pch.h"
#include "../DSVector/DSVector.hpp"

class DSVectorTest : public ::testing::Test
{
protected:
	DSVectorTest()
	{
	}

	virtual ~DSVectorTest()
	{
	}

	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	DSVector<int>	_dsvec;
};


TEST_F(DSVectorTest, DSVectorConstructorTEST){
	EXPECT_EQ(_dsvec.size(), 0);
	EXPECT_EQ(_dsvec.capacity(), 16);
}

TEST_F(DSVectorTest, CopyConstructorTEST){
	DSVector<int> newVec1 = _dsvec;
	EXPECT_EQ(newVec1.size(),0);
	EXPECT_EQ(newVec1.capacity(), 16);

	_dsvec.push_back(10);
	DSVector<int> newVec2 = _dsvec;
	EXPECT_EQ(newVec2.size(), 1);
	EXPECT_EQ(newVec2[0], 10);
}

TEST_F(DSVectorTest, AssignmentOperatorTEST) {
	DSVector<int> newVec;
	newVec.push_back(1);
	EXPECT_EQ(newVec[0], 1);
	_dsvec.push_back(2);
	newVec = _dsvec;
	EXPECT_EQ(newVec.size(), 1);
	EXPECT_EQ(newVec[0], 2);
}

TEST_F(DSVectorTest, resizeMemberFuncTEST) {
	_dsvec.push_back(1);
	_dsvec.push_back(2);
	_dsvec.push_back(3);
	_dsvec.resize(32);//resize length > current size
	EXPECT_EQ(_dsvec.size(), 32);
	EXPECT_EQ(_dsvec.capacity(), 64);
	
	_dsvec.push_back(1);
	_dsvec.push_back(2);
	_dsvec.push_back(3);
	_dsvec.resize(2);		//length < current size.
	EXPECT_EQ(_dsvec.size(), 2);
	EXPECT_EQ(_dsvec.capacity(), 64);
}


TEST_F(DSVectorTest, reserveMemberFuncTEST) {
	_dsvec.push_back(1);
	_dsvec.push_back(3);
	_dsvec.reserve(12);
	EXPECT_EQ(_dsvec.capacity(), 16);

	_dsvec.reserve(18);
	EXPECT_EQ(_dsvec.capacity(), 18);
	EXPECT_EQ(_dsvec.size(), 2);
}

TEST_F(DSVectorTest, isEmptyMemberFuncTEST) {
	EXPECT_EQ(_dsvec.isEmpty(), true);
	_dsvec.push_back(1);
	EXPECT_EQ(_dsvec.isEmpty(), false);
}

TEST_F(DSVectorTest, sizeMemberFuncTEST) {
	EXPECT_EQ(_dsvec.size(), 0);
	_dsvec.push_back(1);
	EXPECT_EQ(_dsvec.size(), 1);
}

TEST_F(DSVectorTest, capacityMemberFuncTEST) {
	EXPECT_EQ(_dsvec.capacity(), DSVector<int>::SPARE_CAPACITY);
	for (int i = 0; i < 18; i++)
		_dsvec.push_back(i);
	EXPECT_EQ(_dsvec.capacity(), 16 * 2+1);
}

TEST_F(DSVectorTest, bracketMemberFuncTEST) {
	_dsvec.push_back(1);
	EXPECT_EQ(_dsvec[0], 1);
}

TEST_F(DSVectorTest, constBracketMemberFuncTEST) {
	_dsvec.push_back(1);
	const DSVector<int> constVec = _dsvec;
	EXPECT_EQ(constVec[0], 1);
}

TEST_F(DSVectorTest, pushbackMemberFuncTEST) {
	_dsvec.push_back(1);
	EXPECT_EQ(_dsvec.size(), 1);
	EXPECT_EQ(_dsvec[0], 1);
}

TEST_F(DSVectorTest, popbackMemberFuncTEST) {
	_dsvec.push_back(1);
	_dsvec.push_back(2);

	_dsvec.pop_back();
	EXPECT_EQ(_dsvec.size(), 1);
	EXPECT_EQ(_dsvec[0], 1);
}

TEST_F(DSVectorTest, backMemberFuncTEST) {
	_dsvec.push_back(1);
	_dsvec.push_back(2);

	EXPECT_EQ(_dsvec.back(), 2);
	_dsvec.pop_back();
	EXPECT_EQ(_dsvec.back(), 1);
}


//insert at front.
TEST_F(DSVectorTest, insertAtFrontMemberFuncTEST) {
	_dsvec.push_back(1);
	_dsvec.push_back(2);
	_dsvec.insert(0, 100);
	EXPECT_EQ(_dsvec.size(), 3);
	EXPECT_EQ(_dsvec[0], 100);
	EXPECT_EQ(_dsvec[1], 1);
	EXPECT_EQ(_dsvec[2], 2);
}

// insert at middle
TEST_F(DSVectorTest, insertAtMiddleMemberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);

	_dsvec.insert(2, 100);
	EXPECT_EQ(_dsvec.size(), 4);
	EXPECT_EQ(_dsvec[0], 0);
	EXPECT_EQ(_dsvec[1], 1);
	EXPECT_EQ(_dsvec[2], 100);
	EXPECT_EQ(_dsvec.back(), 2);
}

// insert at end.
TEST_F(DSVectorTest, insertAtEndMemberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);
	_dsvec.insert(_dsvec.size(), 100);
	EXPECT_EQ(_dsvec.size(), 4);
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(_dsvec[i], i);
	EXPECT_EQ(_dsvec[3], 100);
}


TEST_F(DSVectorTest, eraseAtFrontMemberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);
	
	_dsvec.erase(0);

	EXPECT_EQ(_dsvec.size(), 2);
	EXPECT_EQ(_dsvec[0], 1);
	EXPECT_EQ(_dsvec[1], 2);
}

TEST_F(DSVectorTest, eraseAtMiddleMemberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);
	_dsvec.erase(1);

	EXPECT_EQ(_dsvec.size(), 2);
	EXPECT_EQ(_dsvec[0], 0);
	EXPECT_EQ(_dsvec[1], 2);
}

TEST_F(DSVectorTest, eraseAtEndMemberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);
	EXPECT_EQ(_dsvec.size(), 3);
	_dsvec.erase(2);

	EXPECT_EQ(_dsvec.size(), 2);
	EXPECT_EQ(_dsvec[0], 0);
	EXPECT_EQ(_dsvec[1], 1);
}

TEST_F(DSVectorTest, beginMemeberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);
	EXPECT_EQ(_dsvec.size(), 3);
	EXPECT_EQ(*_dsvec.begin(), 0);
}

TEST_F(DSVectorTest, endMemeberFuncTEST) {
	for (int i = 0; i < 3; i++)
		_dsvec.push_back(i);
	EXPECT_EQ(_dsvec.size(), 3);
	int* ptr = _dsvec.end();
	--ptr;
	EXPECT_EQ(*ptr, 2);
}

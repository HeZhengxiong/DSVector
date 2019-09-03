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
	_dsvec.resize(4);//resize length > current size
	
	_dsvec.push_back(1);
	_dsvec.push_back(2);
	_dsvec.push_back(3);
	_dsvec.resize(2);		//length < current size.
}

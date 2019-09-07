#include "pch.h"

#include "../DSList/DSList.hpp"


class DSListTestFixture : public ::testing::Test
{
protected:
	DSListTestFixture()
	{

	}

	~DSListTestFixture()
	{

	}

	void SetUp() override
	{

	}

	void TearDown() override
	{

	}

	DSList<int>		_dsList;
};


TEST_F(DSListTestFixture, DSListConstructor) {
	EXPECT_EQ(_dsList.size(), 0);
	EXPECT_EQ(_dsList.begin(), _dsList.end());
}

TEST_F(DSListTestFixture, DSListCopyConstructor) {
	DSList<int>	tmpList;
	tmpList.push_back(1);
	tmpList.push_back(2);
	EXPECT_EQ(tmpList.size(), 2);

	DSList<int> tmpList2(tmpList);
	EXPECT_EQ(tmpList2.size(), 2);
	EXPECT_EQ(*tmpList2.begin(), 1);
	EXPECT_EQ(tmpList2.back(), 2);
}


TEST_F(DSListTestFixture, DSListMoveConstructor) {
	
	DSList<int>	tmpList;
	tmpList.push_back(1);
	tmpList.push_back(2);

	DSList<int> tmpList2(std::move(tmpList));
	EXPECT_EQ(tmpList2.size(), 2);
	EXPECT_EQ(*tmpList2.begin(), 1);
	EXPECT_EQ(tmpList2.back(), 2);
}

TEST_F(DSListTestFixture, DSListAssignmentOperator) {
	DSList<int> dslist;
	dslist.push_back(1);
	dslist.push_back(2);
	dslist.push_back(3);

	EXPECT_EQ(dslist.size(),3);
	EXPECT_EQ(dslist.back(),3);
	EXPECT_EQ(*dslist.begin(),1);

	_dsList = dslist;

	EXPECT_EQ(dslist.size(), 3);
	EXPECT_EQ(dslist.back(), 3);
	EXPECT_EQ(*dslist.begin(), 1);

	EXPECT_EQ(_dsList.size(), 3);
	EXPECT_EQ(_dsList.back(), 3);
	EXPECT_EQ(*_dsList.begin(), 1);
}

TEST_F(DSListTestFixture, beginFuc) {
	EXPECT_EQ(_dsList.begin(), _dsList.end());
}

TEST_F(DSListTestFixture, endFunc) {
	_dsList.push_back(1);
	_dsList.push_back(2);
	auto itr = _dsList.end();
	--itr;
	EXPECT_EQ(*itr, 2);
	--itr;
	EXPECT_EQ(*itr, 1);
	EXPECT_EQ(itr, _dsList.begin());
}

TEST_F(DSListTestFixture, constBeginFunc) {
	_dsList.push_back(1);
	_dsList.push_back(2);
	const DSList<int> constDS = _dsList;
	EXPECT_EQ(*constDS.begin(), 1);
}

TEST_F(DSListTestFixture, constEndFunc) {
	_dsList.push_back(1);
	_dsList.push_back(2);
	const DSList<int> constDS = _dsList;
	EXPECT_EQ(*constDS.begin(), 1);
	auto itr = constDS.end();
	--itr;
	EXPECT_EQ(*itr, 2);
}

TEST_F(DSListTestFixture, sizeFunc) {
	EXPECT_EQ(_dsList.size(), 0);
	_dsList.push_front(1);
	EXPECT_EQ(_dsList.size(), 1);
	_dsList.push_back(2);
	EXPECT_EQ(_dsList.size(), 2);
	_dsList.clear();
	EXPECT_EQ(_dsList.size(), 0);
}

TEST_F(DSListTestFixture, emptyFunc) {
	EXPECT_EQ(_dsList.empty(), true);
	_dsList.push_front(1);
	EXPECT_EQ(_dsList.empty(), false);
	_dsList.push_back(2);
	EXPECT_EQ(_dsList.empty(), false);
	_dsList.clear();
	EXPECT_EQ(_dsList.empty(), true);
}

TEST_F(DSListTestFixture, clearFunc) {
	_dsList.push_back(1);
	_dsList.push_front(2);
	EXPECT_EQ(_dsList.empty(), false);
	_dsList.clear();
	EXPECT_EQ(_dsList.empty(), true);
	EXPECT_EQ(_dsList.size(), 0);
}

TEST_F(DSListTestFixture, frontFunc) {
	_dsList.push_front(1);
	_dsList.push_back(2);
	EXPECT_EQ(_dsList.front(), 1);
}

TEST_F(DSListTestFixture, constFrontFunc) {
	_dsList.push_front(1);
	_dsList.push_back(2);
	const DSList<int> constDS = _dsList;
	EXPECT_EQ(constDS.front(), 1);
}

TEST_F(DSListTestFixture, backFunc) {
	for (int i = 0; i < 10; i++)
		_dsList.push_back(i);
	EXPECT_EQ(_dsList.back(), 9);
}

TEST_F(DSListTestFixture, constBackFunc) {
	for (int i = 0; i < 10; i++)
		_dsList.push_back(i);
	DSList<int> constDS = _dsList;
	EXPECT_EQ(constDS.back(), 9);
}

TEST_F(DSListTestFixture, pushFrontFunc) {
	int val1 = 1;
	int val2 = 2;
	_dsList.push_back(val1);
	_dsList.push_front(val2);
	EXPECT_EQ(_dsList.front(), 2);
	_dsList.pop_front();
	EXPECT_EQ(_dsList.front(), 1);
}

TEST_F(DSListTestFixture, pushFrontRValueFunc) {
	_dsList.push_back(1);
	_dsList.push_front(2);
	EXPECT_EQ(_dsList.front(), 2);
	_dsList.pop_front();
	EXPECT_EQ(_dsList.front(), 1);
}

TEST_F(DSListTestFixture, pushBackFunc) {
	int val1 = 1;
	int val2 = 2;
	_dsList.push_back(val1);
	_dsList.push_back(val2);
	EXPECT_EQ(_dsList.back(), 2);
	EXPECT_EQ(_dsList.front(), 1);
}

TEST_F(DSListTestFixture, pushBackRValueFunc) {
	_dsList.push_back(1);
	_dsList.push_back(2);
	EXPECT_EQ(_dsList.back(), 2);
	EXPECT_EQ(_dsList.front(), 1);
}

TEST_F(DSListTestFixture, popFrontFunc) {
	_dsList.push_back(1);
	_dsList.push_back(2);
	EXPECT_EQ(_dsList.front(), 1);
	EXPECT_EQ(_dsList.back(), 2);
	
	_dsList.pop_front();
	EXPECT_EQ(_dsList.size(), 1);
	EXPECT_EQ(_dsList.front(), 2);
	EXPECT_EQ(_dsList.back(), 2);
}

TEST_F(DSListTestFixture, popBackFunc) {
	_dsList.push_front(1);
	_dsList.push_front(2);
	EXPECT_EQ(_dsList.front(), 2);
	EXPECT_EQ(_dsList.back(), 1);

	_dsList.pop_front();
	EXPECT_EQ(_dsList.size(), 1);
	EXPECT_EQ(_dsList.front(), 1);
	EXPECT_EQ(_dsList.back(),1);
}


TEST_F(DSListTestFixture, insertFunc) {
	int v1 = 1;
	int v2 = 2;
	_dsList.insert(_dsList.begin(), v1);
	_dsList.insert(_dsList.begin(), v2);
	EXPECT_EQ(_dsList.front(), 2);
	EXPECT_EQ(_dsList.back(), 1);
	int v3 = 3;
	_dsList.insert(_dsList.end(), v3);
	EXPECT_EQ(_dsList.back(), 3);
}

TEST_F(DSListTestFixture, insertRValueFunc) {
	_dsList.insert(_dsList.begin(), 1);
	_dsList.insert(_dsList.begin(), 2);
	EXPECT_EQ(_dsList.front(), 2);
	EXPECT_EQ(_dsList.back(), 1);
	_dsList.insert(_dsList.end(), 3);
	EXPECT_EQ(_dsList.back(), 3);
}

TEST_F(DSListTestFixture, eraseFunc) {
	_dsList.push_back(1);
	_dsList.push_back(2);
	EXPECT_EQ(_dsList.size(), 2);
	_dsList.erase(_dsList.begin());
	EXPECT_EQ(_dsList.front(), 2);
}

TEST_F(DSListTestFixture, eraseRangeFunc) {
	
	for (int i = 0; i < 10; i++)
		_dsList.push_back(i);

	auto itr = _dsList.begin();
	for (int i = 0; i < 5; i++)
		++itr;

	_dsList.erase(_dsList.begin(), itr);

	EXPECT_EQ(_dsList.size(), 5);
	EXPECT_EQ(_dsList.front(), 5);
}



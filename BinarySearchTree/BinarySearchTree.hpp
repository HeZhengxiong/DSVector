#ifndef BinarySearchTree_h__
#define BinarySearchTree_h__

#include <iostream>


template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	BinarySearchTree(BinarySearchTree&& rhs);
	BinarySearchTree& operator=(const BinarySearchTree& other);
	BinarySearchTree& operator=(BinarySearchTree&& other);
	~BinarySearchTree();


	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T& x) const;
	bool isEmpty() const;
	void printTree(std::ostream& out = std::cout) const;

	void makeEmpty();
	void insert(const T& x);
	void insert(T&& x);
	void remove(const T& x);


private:
	struct BinaryNode 
	{
		T			_nodeData;
		BinaryNode	_leftNode;
		BinaryNode	_rightNode;

		BinaryNode(const T& t, BinaryNode* l, BinaryNode* r) : 
			_nodeData{ t }, _leftNode{ l }, _rightNode{ r }{ }
		BinaryNode(T&& t, BinaryNode* l, BinaryNode* r) : _nodeData{ std::move(t) },
			_leftNode{ l }, _rightNode{ r }{ }
	};

};







#endif // BinarySearchTree_h__

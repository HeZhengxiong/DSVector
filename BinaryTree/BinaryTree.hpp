#ifndef BinaryTree_h__
#define BinaryTree_h__

#include <string>
#include "../ArrayQueue/ArrayQueue.hpp"
template <typename T>
class BinaryTree
{
	struct Node
	{
		T		_nodeData;
		Node*	_nodeLeft;
		Node*	_nodeRight;

		Node(T data, 
			Node* left = nullptr,
			Node* right = nullptr) :
			_nodeData( data ),
			_nodeLeft{ left },
			_nodeRight{ right }{}
	};


public:
	BinaryTree()
	{
		//Node* no4Node = new Node("4");
		//Node* no5Node = new Node("5");
		//Node* no2Node = new Node("2", no4Node, no5Node);

		//Node* no3Node = new Node("3");
		//_root = new Node("1", no2Node, no3Node);

		Node* node4 = new Node("4");
		Node* node5 = new Node("5");
		Node* node3 = new Node("3", node4, node5);
		Node* node2 = new Node("2");
		_root = new Node("1", node2, node3);
	}

	~BinaryTree()
	{
		clearNode(_root);
	}


	//Depth First Traversal
	std::string postOrder()
	{
		return postOrderString(_root);
	}

	std::string preOrder()
	{
		return preOrderString(_root);
	}

	std::string inOrder()
	{
		return inOrderString(_root);
	}

	int height()
	{
		return heightRecursive(_root);
	}

	//Breadth First Traversal
	std::string breadthOrder()
	{
		std::string str;
		int h = heightRecursive(_root);
		for (int i = 0; i <= h; ++i)
		{
			str += getStringOnLevel(_root, i);
		}
		return str;
	}


	std::string breadthOrder_queue()
	{
		std::string str;
		if (!_root)
			return str;

		ArrayQueue<Node*> linkedQueue;
		Node *tempNode = _root;
		linkedQueue.enqueue(tempNode);
		
		while (!linkedQueue.isEmpty())
		{
			tempNode = linkedQueue.front();
			str += tempNode->_nodeData;
			linkedQueue.dequeue();

			if (tempNode->_nodeLeft)
				linkedQueue.enqueue(tempNode->_nodeLeft);
			if (tempNode->_nodeRight)
				linkedQueue.enqueue(tempNode->_nodeRight);
		}

		return str;
	}


private:
	void clearNode(Node* treeRoot)
	{
		if (!treeRoot)
			return;

		if (treeRoot->_nodeRight)
			clearNode(treeRoot->_nodeLeft);

		if (treeRoot->_nodeRight)
			clearNode(treeRoot->_nodeRight);

		delete treeRoot;
	}

	std::string inOrderString(Node* subTreeRoot)
	{
		std::string retString;

		if (subTreeRoot)
		{
			if (subTreeRoot->_nodeLeft)
			{
				retString += inOrderString(subTreeRoot->_nodeLeft);
			}

			retString += subTreeRoot->_nodeData;

			if (subTreeRoot->_nodeRight)
			{
				retString += inOrderString(subTreeRoot->_nodeRight);
			}
		}

		return retString;
	}

	std::string preOrderString(Node* subTreeRoot)
	{
		std::string retString;
		if (subTreeRoot)
		{
			retString += subTreeRoot->_nodeData;
			if (subTreeRoot->_nodeLeft)
				retString += preOrderString(subTreeRoot->_nodeLeft);
			if (subTreeRoot->_nodeRight)
				retString += preOrderString(subTreeRoot->_nodeRight);
		}
		return retString;
	}

	std::string postOrderString(Node* subTreeRoot)
	{
		std::string retString;
		if (subTreeRoot)
		{
			if (subTreeRoot->_nodeLeft)
				retString += postOrderString(subTreeRoot->_nodeLeft);
			if (subTreeRoot->_nodeRight)
				retString += postOrderString(subTreeRoot->_nodeRight);
			retString += subTreeRoot->_nodeData;
		}
		return retString;
	}

	int heightRecursive(Node* subTreeRoot)
	{
		if (!subTreeRoot)
			return -1;
		else
		{
			int lHeight = heightRecursive(subTreeRoot->_nodeLeft);
			int rHeight = heightRecursive(subTreeRoot->_nodeRight);

			if (lHeight > rHeight)
				return lHeight + 1;
			else
				return rHeight + 1;
		}
	}

	int height_r(Node* sr)
	{
		if (!sr)
		{
			return -1;
		}
		else
		{
			int lh = height_r(sr->_nodeLeft);
			int rh = height_r(sr->_nodeRight);
			
			return (lh > rh ? lh : rh) + 1
		}
	}


	public:
	std::string getStringOnLevel(Node* subRoot, int level)
	{
		std::string str;

		if (!subRoot)
			return str;

		if (0 == level)
		{
			str = subRoot->_nodeData;
		}
		else if (level > 0)
		{
			str += getStringOnLevel(subRoot->_nodeLeft, level - 1);
			str += getStringOnLevel(subRoot->_nodeRight, level - 1);
		}

		return str;
	}


	Node* _root;
};




#endif // BinaryTree_h__

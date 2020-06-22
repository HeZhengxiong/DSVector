#ifndef BPlusTree_h__
#define BPlusTree_h__


template<typename T>
struct Record
{
	Record() : record(T()){ }
	~Record(){ }

	T	record;
};




template<typename U>
class Node 
{
	int		keyCnt;	//key cnt
	U		keys[];//keys
	Node*	ptrs[];//ptr point to child to indicate search
	Node*	parent;//parent
	Node*	next;//record stored in leaf node, extra next ptr to link
	             // all these records
	bool		isLeaf; //whether the node is leaf node.
};



class BPlusTree
{
	const static int DEFAULT_ORDER = 4;

public:
	BPlusTree(int order=DEFAULT_ORDER){}
	~BPlusTree(){}





private:
	Node* _root;
};














#endif // BPlusTree_h__



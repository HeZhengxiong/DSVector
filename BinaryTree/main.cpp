#include "BinaryTree.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	BinaryTree<std::string> tree;

	std::cout << "PreOrder: " << tree.preOrder() << std::endl;
	//std::cout << "PostOrder: " << tree.postOrder() << std::endl;
	//std::cout << "InOrder: " << tree.inOrder() << std::endl;

	//std::cout << "Height: " << tree.height() << std::endl;
	std::cout << "LevelOrder: " << tree.breadthOrder_queue() << std::endl;

	//std::cout << "Print Level NO1$: " << tree.getStringOnLevel(tree._root,2) << std::endl;

	return 0;
}
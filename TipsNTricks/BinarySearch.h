#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <string.h>
#include <stdio.h>

class BinaryTree {
public:
	typedef struct Node {
		Node* left;
		Node* right;
		int value;
	}Node;

	BinaryTree();
	BinaryTree(int const* const array, size_t size);
	~BinaryTree();

	void insert(int value);
	void dump();
	bool search(int value);
private:
	Node* m_tree;

	void doInsert(Node** node, int value);
	void destroy(Node* node);
	void doDump(Node* node);
	bool doSearch(Node* node, int value);
};

#endif //BINARYSEARCH_H
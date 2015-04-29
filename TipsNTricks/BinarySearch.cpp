#include "BinarySearch.h"

BinaryTree::BinaryTree() : m_tree(0) {}

BinaryTree::BinaryTree(int const* const array, size_t size) : m_tree(0) {
	for(int i = 0; i < size; ++i) {
		doInsert(&m_tree, array[i]);
	}
}

BinaryTree::~BinaryTree() {
	destroy(m_tree);
}

void BinaryTree::insert(int value) {
	doInsert(&m_tree, value);
}

void BinaryTree::doInsert(Node** node, int value) {
	if(*node == NULL) {
		*node = new Node;
		if(*node != NULL) {
			(*node)->left = 0;
			(*node)->right = 0;
			(*node)->value = value;
		}
	} else if(value <= (*node)->value) {
		doInsert(&(*node)->left, value);
	} else {
		doInsert(&(*node)->right, value);
	}
}

void BinaryTree::dump() {
	doDump(m_tree);
}

void BinaryTree::doDump(Node* node) {
	if(node != NULL) {
		doDump(node->left);
		printf("%d\n", node->value);
		doDump(node->right);
	}
}
void BinaryTree::destroy(Node* node) {
	if(node != NULL) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

bool BinaryTree::search(int value) {
	return doSearch(m_tree, value);
}

bool BinaryTree::doSearch(Node* node, int value) {
	if(node != NULL) {
		if(value < node->value) {
			doSearch(node->left, value);
		} else if (value > node->value) {
			doSearch(node->right, value);
		} else {
			return true;
		}
	} else {
		return false;
	}
    
    return true;
}
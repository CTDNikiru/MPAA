#include "set.h"
#include <iostream>

// A node of a binary tree.
struct TreeNode {
	int elem;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int elem = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) :
		elem(elem), left(left), right(right) {			
	}
};

int treeSize(const TreeNode *node) {
	// Get size of the tree recursively.
	if (!node) {
		return 0;
	}
	return 1 + treeSize(node->left) + treeSize(node->right);
}

void treeDelete(TreeNode* node) {
	// Delete the tree recursively.
	if (!node) {
		return;
	}
	treeDelete(node->left);
	treeDelete(node->right);
	delete node;
}

Set::Set() {    

}

Set::~Set() {    
	// Destroy the tree.
    treeDelete(root);
}


void pushInTree(int elem, TreeNode** tree) {
	if (*tree == nullptr) {
		*tree = new TreeNode;
		(*tree)->elem = elem;
		return;
	}

	if (elem == (*tree)->elem) {
		return;
	}
	else if (elem > (*tree)->elem) {
		pushInTree(elem, &(*tree)->right);
	}
	else { pushInTree(elem, &(*tree)->left); }
}

bool findInTree(int elem, TreeNode* tree, int size) {
	while (tree != nullptr)
	{
		if (tree->elem == elem) {
			return true;
		}
		else if (tree->elem < elem) {
			tree = tree->right;
		}
		else
		{
			tree = tree->left;
		}
	}
	return false;
}

void Set::insert(int elem) {
    // Insert the element into the set.
    // If the element is in the set already, do nothing.
	// Inserting is done by creating new tree nodes, i.e. node = new TreeNode(elem),
	// then adding them to the tree: root = node, 
	//or parent->left = node, or parent->right = node.

	pushInTree(elem, &(root));
}

bool Set::find(int elem) const {
    // Return true if the element is in the set, false otherwise.
	bool result = findInTree(elem, root, Set::size());
	return result;
}

int Set::size() const {
    // Return number of elements in the set.
    return treeSize(root);    
}
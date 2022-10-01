#include "BinaryTree.h"

#pragma region TreeNode
BinaryTree<class Key, class T>::TreeNode::TreeNode(Key* key, T* value) : DataNode(value) {
	leftBranch = nullptr;
	rightBranch = nullptr;
	this->key = key;
}

void BinaryTree<class Key, class T>::TreeNode::updateCount() {
	childrenCount = 0;
	if (leftBranch != nullptr) {
		childrenCount += leftBranch->childrenCount;
	}
	if (rightBranch != nullptr) {
		childrenCount += rightBranch->childrenCount;
	}
}
#pragma endregion

BinaryTree<class Key, class T>::BinaryTree() {
	root = nullptr;
}

void BinaryTree<class Key, class T>::Add(Key* key, T* value) {

	if (root == nullptr) {
		root = new TreeNode(key, value);
		return;
	}

	if (*(root->key) < *key) {

	}

}
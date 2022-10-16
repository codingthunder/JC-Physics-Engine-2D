//#include "BinaryTree.h"
//#include <iostream>
//
//#pragma region TreeNode
//template<class Key, class T>
//TreeNode<Key, T>::TreeNode(Key* key, T* value) : DataNode(value) {
//	leftBranch = nullptr;
//	rightBranch = nullptr;
//	this->key = key;
//}
//
//template<class Key, class T>
//TreeNode<Key,T>* TreeNode<Key,T>::getUncle() {
//	TreeNode<Key,T>* parent = this->parentBranch;
//	if (parent == nullptr) {
//		return nullptr;
//	}
//
//	TreeNode<Key,T>* grandParent = parent->parentBranch;
//
//	if (grandParent == nullptr) {
//		return nullptr;
//	}
//
//	TreeNode<Key,T>* uncle = nullptr;
//
//	if (parent == grandParent->leftBranch) {
//		uncle = grandParent->rightBranch;
//	}
//	else {
//		uncle = grandParent->leftBranch;
//	}
//
//	return uncle;
//
//}
//#pragma endregion
//
//template<class Key, class T>
//RedBlackTree<Key, T>::RedBlackTree() {
//	root = nullptr;
//	std::cout << "RedBlack Tree is successfully built.";
//}
//
//template <class Key, class T>
//T* RedBlackTree<Key,T>::search(Key* key) {
//	TreeNode<Key,T>* currentNode = root;
//
//	while (true) {
//		if (currentNode->key == nullptr || *currentNode->key == *key) {
//			return currentNode->data;
//		}
//		if (*key < *currentNode->key) {
//			currentNode = currentNode->leftBranch;
//			continue;
//		}
//		if (*key > *currentNode->key) {
//			currentNode = currentNode->rightBranch;
//			continue;
//		}
//		//Technically, this last if statement isn't necessary, but I may keep it just for readability's sake.
//	}
//}
//
//template<class Key, class T>
//void RedBlackTree<Key,T>::add(Key* key, T* value) {
//
//
//	TreeNode<Key,T>* currentNode = root;
//	TreeNode<Key,T>* parentNode = nullptr;
//	TreeNode<Key,T>* grandpaNode = nullptr;
//	TreeNode<Key,T>* uncleNode = nullptr;
//
//	bool isLeft;
//
//	//Insertion.
//	while (true) {
//
//		if (*(currentNode->key) == *key) {
//			return;
//		}
//
//		if (currentNode == nullptr) {
//			currentNode = new TreeNode(key, value);
//			currentNode->parentBranch = parentNode;
//			if (parentNode != nullptr) {
//				if (isLeft) {
//					parentNode->leftBranch = currentNode;
//				}
//				else {
//					parentNode->rightBranch = currentNode;
//				}
//			}
//			break;
//		}
//
//		isLeft = *(currentNode->key) > *key;
//
//		parentNode = currentNode;
//
//		if (isLeft) {
//			currentNode = currentNode->leftBranch;
//		}
//		else {
//			currentNode = currentNode->rightBranch;
//		}
//	}
//
//	while (true) {
//
//		parentNode = currentNode->parentBranch;
//
//		if (currentNode->parentBranch == nullptr) {
//			currentNode->isBlack = true;
//			return;
//		}
//		if (currentNode->parentBranch->isBlack) {
//			return;
//		}
//
//		grandpaNode = parentNode->parentBranch;
//
//		uncleNode = currentNode->getUncle();
//		if (uncleNode == nullptr) {
//			return;
//		}
//		//If the uncle is red:
//		if (!uncleNode->isBlack) {
//
//			currentNode->parentBranch->isBlack = true;
//			uncleNode->isBlack = true;
//			currentNode = uncleNode->parentBranch;
//			currentNode->isBlack = false;
//		}
//		else {
//			//Do Rotation stuff, then return.
//
//			//L1 and L2 are used to determine the following cases: LL, LR, RR, RL
//			bool L1 = *parentNode < *grandpaNode;
//			bool L2 = *currentNode < *parentNode;
//
//			if (L1) {
//				if (!L2) {
//					//Do LR. LL will always follow an LR.
//					leftRotate(parentNode);
//				}
//				//Do LL
//				rightRotate(grandpaNode);
//				grandpaNode->isBlack = !grandpaNode->isBlack;
//				parentNode->isBlack = !parentNode->isBlack;
//			}
//			else {
//				if (L2) {
//					//Do RL. RR will always follow RL.
//					rightRotate(parentNode);
//				}
//				//Do RR
//				leftRotate(grandpaNode);
//				grandpaNode->isBlack = !grandpaNode->isBlack;
//				parentNode->isBlack = !parentNode->isBlack;
//			}
//		}
//	}
//}
//
//
//#pragma region InternalFunctions
//
//template<class Key, class T>
//void RedBlackTree<Key,T>::leftRotate(TreeNode<Key,T>* baseNode) {
//	TreeNode<Key,T>* rightNode = baseNode->rightBranch;
//	TreeNode<Key,T>* orphan = nullptr;
//
//	if (rightNode != nullptr) {
//		orphan = rightNode->leftBranch;
//		rightNode->parentBranch = baseNode->parentBranch;
//		rightNode->leftBranch = baseNode;
//		
//	}
//	if (orphan != nullptr) {
//		orphan->parentBranch = baseNode;
//	}
//
//	baseNode->parentBranch = rightNode;
//	baseNode->rightBranch = orphan;
//}
//
//template<class Key, class T>
//void RedBlackTree<Key, T>::rightRotate(TreeNode<Key, T>* baseNode) {
//	TreeNode<Key,T>* leftNode = baseNode->leftBranch;
//	TreeNode<Key,T>* orphan = nullptr;
//
//	if (leftNode != nullptr) {
//		orphan = leftNode->rightBranch;
//		leftNode->parentBranch = baseNode->parentBranch;
//		leftNode->rightBranch = baseNode;
//
//	}
//	if (orphan != nullptr) {
//		orphan->parentBranch = baseNode;
//	}
//
//	baseNode->parentBranch = leftNode;
//	baseNode->leftBranch = orphan;
//
//}
//
//
//template<class Key, class T>
//TreeNode<Key,T>* RedBlackTree<Key,T>::selectBranch(TreeNode<Key,T>* currentNode, Key* key) {
//
//	if (*(currentNode->key) > *key) {
//		return currentNode->leftBranch;
//	}
//
//	if (*(currentNode->key) < *key) {
//		return currentNode->rightBranch;
//	}
//
//	return currentNode;
//}
//#pragma endregion
//

#pragma once
#include "DataNode.h"
#include <limits>

//I considered making the positioning a generic as well, but I couldn't imagine using anything for it except floats.
//I also considered using my Vector2 class, but I didn't want to tightly couple this to that.
//Finally, my goal is neither rapid insertion nor deletion, and not even rapid lookup. My goal is to walk the tree every loop
//and check for overlapping colliders. By implementing it this way, I THINK I can approach O(n) for time complexity.
template<class T> class QuadTree {

private:

	enum QuadrantEnum {
		NE,
		NW,
		SE,
		SW
	};

	struct QuadNode : public DataNode<T> {
		QuadNode(float xPos, float yPos, T* value);
		float xPos = 0;
		float yPos = 0;
		float northBounds = std::numeric_limits<float>::infinity;
		float southBounds = std::numeric_limits<float>::infinity;
		float westBounds = std::numeric_limits<float>::infinity;
		float eastBounds = std::numeric_limits<float>::infinity;

		QuadNode* parentNode = nullptr;
		QuadNode* childNE = nullptr;
		QuadNode* childNW = nullptr;
		QuadNode* childSE = nullptr;
		QuadNode* childSW = nullptr;
	};

	QuadNode* root = nullptr;

	void addNode(QuadNode* newNode);
	QuadNode* closestNode(float posX, float posY);
	removeClosestNode(float posX, float posY);

};
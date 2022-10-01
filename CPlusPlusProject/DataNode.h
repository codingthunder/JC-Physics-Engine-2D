#pragma once

template <class T> class DataNode {

protected:
	T* dataPtr;

public:
		explicit DataNode(T* arg);
		T* data();
};
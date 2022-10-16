#pragma once

template <class T> class DataNode {

protected:
	T* dataPtr;

public:
	DataNode(T* arg) : dataPtr(arg) {
	}

	T* data() {
		return dataPtr;
	}
};
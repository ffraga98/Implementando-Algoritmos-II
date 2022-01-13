#ifndef CIRCLE_LIST_H
#define CIRCLE_LIST_H

#include "Node.h"

const int NO_ELEMENT = 0;
const int FIRST_ELEMENT_INDEX = 1;
template<typename T>
class CircleList{
private:
	Node<T>* first_;
	int size_;
public:
	CircleList() : first_(nullptr), size_(NO_ELEMENT){}



};

#endif
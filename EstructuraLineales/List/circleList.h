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

	Node<T>* search_element(int pos){
		Node<T>* aux = first_;
		for(int i = FIRST_ELEMENT_INDEX; i < pos; i++){
			aux = aux -> getNext();
		}
		return aux;
	}
public:
	CircleList() : first_(nullptr), size_(NO_ELEMENT){}

	~CircleList(){}

	bool empty(){
		return size_ == NO_ELEMENT;
	}
	
	bool size(){
		return size_;
	}

	void insert(const T& data, const int& pos){
		Node<T>* newNode = new Node<T>(data);

		if(empty() && pos == FIRST_ELEMENT_INDEX){
			first_ = newNode;
			first_ -> setNext(first_);
		}else if(pos == FIRST_ELEMENT_INDEX){
			Node<T>* nodeAux = search_element(size_);
			nodeAux -> setNext(newNode);
			newNode -> setNext(first_);
			first_ = newNode;
		}else if( pos == size_){
			Node<T>* nodeAux = search_element(pos);
			nodeAux -> setNext(newNode);
			newNode -> setNext(first_);
		}else if(FIRST_ELEMENT_INDEX <= pos && pos <= size_){
			Node<T>* nodeAux = search_element(pos);
 			newNode -> setNext(nodeAux);
 			nodeAux = search_element(pos - 1);
 			nodeAux -> setNext(newNode);
		}
		++size_;
	}

	T operator[](int pos){
		T aux = T();
		if(FIRST_ELEMENT_INDEX <= pos && pos <= size_){
			aux = search_element(pos) -> getData();
		}
		return aux;
	}

};

#endif
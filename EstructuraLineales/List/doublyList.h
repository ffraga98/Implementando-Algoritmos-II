#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include "doublyNode.h"

const int NO_ELEMENT = 0;
const int FIRST_ELEMENT_INDEX = 1;

template<typename T>
class doublyList{
private:
	Node<T>* first_;
	Node<T>* last_;
	int size_;

	Node<T>* search_element(int pos){
		Node<T>* aux = first_;
		for(int i = FIRST_ELEMENT_INDEX; i < pos; i++){
			aux = aux -> getNext();
		}
		return aux;
	}

public:
	doublyList() : first_(nullptr), last_(nullptr), size_(NO_ELEMENT){}

	~doublyList(){
		while(!empty()){
			pop_back();
		}
	}

	bool empty(){
		return size_ == NO_ELEMENT;
	};

	int size(){
		return size_;
	};

	void insert(const T& data, const int& pos){
		Node<T>* newNode = new Node<T>(data);

		if(empty()){
			first_ = newNode;
			last_ = newNode;
		}else if(pos == FIRST_ELEMENT_INDEX){
			newNode -> setNext(first_);
			first_ -> setPrevious(newNode);
			first_ = newNode;
		}else if( pos == size_ + 1){
			newNode -> setPrevious(last_);
			last_ -> setNext(newNode);
			last_ = newNode;
		}else if( FIRST_ELEMENT_INDEX < pos && pos <= size_){
			Node<T>* nextNode = search_element(pos);
			Node<T>* previousNode = nextNode -> getPrevious();
			newNode -> setNext(nextNode);
			newNode -> setPrevious(previousNode);
			nextNode -> setPrevious(newNode);
			previousNode -> setNext(newNode);
		}

		++size_;
	};

	void push_back(const T& data){
		insert(data,size_ + 1);
	}

	void push_front(const T& data){
		insert(data, FIRST_ELEMENT_INDEX);
	}

	void erase(const int& pos){
		Node<T>* nextNode;
		Node<T>* previousNode;
		Node<T>* erasedNode;

		if(pos == FIRST_ELEMENT_INDEX){
			nextNode = first_ -> getNext();
			nextNode -> setPrevious(nullptr); //que es lo mismo que previous de first_

			erasedNode = first_;

			first_ = nextNode;
		}else if(pos == size_){
			previousNode = last_ -> getPrevious();
			previousNode -> setNext(nullptr); //que es lo mismo que el next de last_
			
			erasedNode = last_;

			last_ = previousNode;
		}else if(FIRST_ELEMENT_INDEX < pos && pos < size_){
			erasedNode = search_element(pos);
			nextNode = erasedNode -> getNext();
			previousNode = erasedNode -> getPrevious();

			nextNode -> setPrevious(previousNode);
			previousNode -> setNext(nextNode);

		}
		delete erasedNode;
		--size_;
	};

	void pop_back(const T& data){
		erase(data,size_);
	}

	void pop_front(const T& data){
		erase(data, FIRST_ELEMENT_INDEX);
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
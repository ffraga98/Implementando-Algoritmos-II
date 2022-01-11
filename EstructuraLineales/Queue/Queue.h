#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

template <typename T>
class Queue {
private:
	Node<T>* first;
	Node<T>* last;

public:	
	Queue() : first(nullptr), last(nullptr){}
	
	~Queue(){
		while(!empty())
			pop_front();
	}

	bool empty(){
		return first == nullptr;
	}

	void pop_front(){
		if(!empty()){
			T data = first -> getData();
			Node<T> * aux  = first -> getNext();
			delete first;
			first = aux;
		}
	}

	void push_back(T data){
		Node<T>* newNode = new Node<T>(data);
		if(empty()){
			first = newNode;
		}else{
			last -> setNext(newNode);
		}
		last = newNode;
	}

	T front(){
		return first -> getData();
	}

	T back(){
		return last -> getData();
	}

	std::size_t size(){
		std::size_t queue_size = 0;
		Node<T>* aux = first;

		while(aux != nullptr){
			aux = aux -> getNext();
			++queue_size;
		}
		
		return queue_size;
	}

};

#endif 
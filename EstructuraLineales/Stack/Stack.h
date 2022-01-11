#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

template <typename T>
class Stack {
private:
	Node<T>* last;

	void removeLast(){
		Node<T>* newLast = last -> getNext();
		delete last;
		last = newLast;
	}

	void cleanStack(){
		while(!isEmpty()){
			removeLast();
		}
	}

	const T& operator[](const std::size_t index) const {
		Node<T>* aux = last;
		std::size_t actualSize = size();

		for(std::size_t i = 0; i < index && index < actualSize; i++){
			aux = aux -> getNext();
		}
		return aux -> getData();
	}

public:
	Stack() : last(nullptr){};

	~Stack(){
		cleanStack();
	}

	void push(const T& data) {
		Node<T>* node = new Node<T>(data);
		node -> setNext(last);
		last = node;
	}

	// Unicamente elimina el siguiente elemento de la fila. Para acceder al siguiente, usar top().
	void pop() {
		if(!isEmpty())
			removeLast();
	}

	T top() const { 
		if(!isEmpty()){
			return last -> getData();
		}
		return {};
	} 

	bool isEmpty() const{
		return last == nullptr;
	}

	std::size_t size() const {
		Node<T>* next = last;
		std::size_t sizeStack = 0;
		std::cout << "Hola";
		while(next != nullptr){
			sizeStack++;
			next = next -> getNext();
		}
		
		return sizeStack;	
	}


};

#endif
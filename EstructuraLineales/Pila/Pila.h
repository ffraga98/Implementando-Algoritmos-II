#include <iostream>
#include "Nodo.h"

const std::size_t EMPTY_STACK = 0;

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

public:
	Stack() : last(nullptr){};

/* Arreglar constructor de copia.
	Stack(const Stack& rhs) {
		std::size_t i = 0;
		Stack aux;
		while(i < rhs.size()){
			aux.push(rhs[i]);
			++i;
		}
		//cleanStack();
		i = 0;
		while(i < rhs.size()){
			this -> push(aux.top());
			aux.pop();
			++i;
		}
	}
*/
	const T& operator[](const std::size_t index) const {
		Node<T>* aux = last;
		for(std::size_t i = 0; i < index && index < size(); i++){
			aux = aux -> getNext();
		}
		return aux -> getData();
	}

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
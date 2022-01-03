#include "Nodo.h"

template <typename T>
#include "StackEmptyException.h"

class Stack {
private:
	Node<T>* last;

	T pop_() throw() {
		if(isEmpty())
			throw StackEmptyException();
		else{
			T data = last -> getData();
			updateLast();
			return data;
		}
	}

	void updateLast(){
		Node<T>* newLast = last -> getNext();
		delete last;
		last = newLast;
	}

public:
	Stack() {
		last = nullptr;
	}

	void push(const T& data) {
		Node<T>* node = new Node<T>(data);
		node -> setNext(last);
		last = node;
	}

	T pop() {
		try{
			pop_()
		} catch (std::exception e){
			cout << e.what() << endl;
		}
	}

	bool isEmpty() const{
		return last == nullptr;
	}
};
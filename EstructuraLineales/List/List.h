#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

const int FIRST_ELEMENT_INDEX = 1;
const int NO_ELEMENT = 0;

template<typename T>
class List{
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
	List() : first_(nullptr), size_(NO_ELEMENT){}
	
	~List(){
		while(!empty()){
			pop_back();
		}
	}

	T front() {
		return first_ -> getData();
	}

	T back() {
		return search_element(size_) -> getData();
	}

	std::size_t size(){
		return size_;
	}

	bool empty(){
		return size_ == NO_ELEMENT;
	}

	void insert(const T& data, const int& pos){
		Node<T>* newNode = new Node<T>(data);
		
		newNode -> setNext(search_element(pos)); 
		if (pos == FIRST_ELEMENT_INDEX){
			first_ = newNode;
		}else if(pos <= size_ + 1){
			search_element(pos - 1) -> setNext(newNode);
		}

		size_++;
	}

	void erase(const int& pos){
		Node<T>* erasedNode = search_element(pos);
		Node<T>* nextNode = erasedNode -> getNext();

		if (pos == FIRST_ELEMENT_INDEX){
			first_ = nextNode; 
		}else if (pos <= size_){
			search_element(pos-1) -> setNext(nextNode);
		}

		delete erasedNode;
		--size_;
	}

	void push_back(const T& data){
		insert(data, size_ + 1);
	}

	void push_front(const T& data){
		insert(data, FIRST_ELEMENT_INDEX);
	}

	void pop_back(){
		erase(size_);
	}

	void pop_front(){
		erase(FIRST_ELEMENT_INDEX);
	}

	void assign(const T& data, const int& pos){
		search_element(pos) -> setData(data);
	}

	void swap(const int& pos1, const int& pos2){
		T data1 = search_element(pos1) -> getData();
		T data2 = search_element(pos2) -> getData();
		assign(data2,pos1);
		assign(data1,pos2);
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
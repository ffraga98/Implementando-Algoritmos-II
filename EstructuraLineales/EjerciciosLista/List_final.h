#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node_final.h"

const int FIRST_ELEMENT_INDEX = 1;
const int NO_ELEMENT = 0;

template<typename T>
class List{
private:
	Node<T>* first_;
	int size_;

	// Returns the pos-th node on the list.
	Node<T>* search_element(int pos){
		Node<T>* aux = first_;
		
		for(int i = FIRST_ELEMENT_INDEX; i < pos; i++){
			aux = aux -> getNext();
		}

		return aux;
	}

public:
	List() : first_(nullptr), size_(NO_ELEMENT){}

	List(List<T> & rhs){
		size_ = 0;
		
		for(int i = FIRST_ELEMENT_INDEX; i <= rhs.size(); i++)
			this -> push_back(rhs[i]);

	}

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

	int size(){
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

	// size_ != 0;
	T erase(const int& pos){
		Node<T>* erasedNode = search_element(pos);
		Node<T>* nextNode = erasedNode -> getNext();

		if (pos == FIRST_ELEMENT_INDEX){
			first_ = nextNode; 
		}else if (pos <= size_){
			search_element(pos-1) -> setNext(nextNode);
		}

		T data = erasedNode -> getData();
		delete erasedNode;
		--size_;

		return data;
	}

	void push_back(const T& data){
		insert(data, size_ + 1);
	}

	void push_front(const T& data){
		insert(data, FIRST_ELEMENT_INDEX);
	}

	T pop_back(){
		return erase(size_);
	}

	T pop_front(){
		return erase(FIRST_ELEMENT_INDEX);
	}

	void assign(const T& data, const int& pos){
		search_element(pos) -> setData(data);
	}

	//Ejercicios de Final
	//1. Metodo de que, dadas dos posiciones, intercambia sus datos.
	void swap(const int& pos1, const int& pos2){
		T data1 = search_element(pos1) -> getData();
		T data2 = search_element(pos2) -> getData();
		assign(data2,pos1);
		assign(data1,pos2);
	}

	T operator[](const int pos){
		T aux = T();
		if(pos >= FIRST_ELEMENT_INDEX && pos <= size_){
			aux = search_element(pos) -> getData();
		}
		return aux;
	}

	List<T>& operator=(List<T> rhs){
		size_ = rhs.size();
		first_ = rhs[FIRST_ELEMENT_INDEX];

		return *this;
	}

	void print(){
		Node<T>* aux = first_;
		for(int i = FIRST_ELEMENT_INDEX; i <= size_; i++){
			std::cout << aux -> getData() << std::endl;
			aux = aux -> getNext();
		}
	}

	//2. Metodo que une la lista original con otra que se pasa por párametro.
	// Modificando a la lista que llama. La lista pasada por parametro va al final. 

	void append_list(List l){
		for(int i = FIRST_ELEMENT_INDEX; i <= l.size(); i++){
			this -> push_back(l[i]);
		}
	}

	//3. Metodo que une la lista original con otra que se pasa por párametro.
	// Devolviendo un puntero a la nueva lista. La lista pasada por parametro va al final. 
	
	List<T>* union_list(List l){
		List<T>* new_list = new List();
		Node<T>* aux = first_;

		for(int i = FIRST_ELEMENT_INDEX; i <= size_; i++){
			new_list -> push_back(aux -> getData());
			aux = aux -> getNext();
		}
		for(int i = FIRST_ELEMENT_INDEX; i <= l.size(); i++){
			new_list -> push_back(l[i]);
		}

		return new_list;
	}

	//4. Método que revierte la lista, modificandola.
	void reverse_list(){
		Node<T>* node1 = search_element(size_);
		Node<T>* new_first = node1;
		Node<T>* node2;

		for(int i = size_; i > 1; --i){
			node2 = search_element(i-1);
			node1 -> setNext(node2);
			node1 = node2; 
		}
		node1 -> setNext(nullptr);
		first_ = new_first;
	}

	//5. Método que revierte la lista, creando una nueva y retornando el puntero.

	List<T>* reverse_list_ptr(){
		List<T>* new_list = new List();
		
		for(int i = 1; i <= size_; i++){
			new_list -> push_front(search_element(i) -> getData());
		}

		return new_list;
	}

	//6. Metodo que recibe una lista por parametro, ambas estan ordenadas, se hace 
	// un merge entre las dos, modificando la original, que tiene que quedar ordenada
	// y sin elementos repetidos.

	void merge_ordered_list(List l){
		//Al estar ambas ordenadas, con comparar los numeros mas pequeños es suficiente con saber cual me quedo.
		int i = 1, j = 1, pos = 1;

		//Solo para simular que tengo el metodo comparar.
		Node<T> data1 = Node<T>((*this)[i]);
		Node<T> data2 = Node<T>(l[j]);

		while(i <= size_ && j <= l.size()){	
			switch( data1.compare_to(data2)){
				case 0: 
					data2.setData(l[++j]);
				case -1:
					data1.setData((*this)[++i]);	
					break;
				case 1:
					this -> insert(data2.getData(),pos);
					data2.setData(l[++j]);
					break;
				default:
					std::cout << "?" << std::endl;
				
			}
			++pos;
		}

		while( j <= l.size()){
			this -> push_back(data2.getData());
			data2.setData(l[++j]);
		}
	}

	//7. Metodo que elimina un dato: se pasa un
	// dato por parametro y se elimina la primera ocurrencia.
	// Usar el metodo comparar. Si no lo encuentra no hace nada.

	//(Lo facilita tener una funcion lista para borrar por posición.)
	void erase_data(const T& data){
		int pos = 1;
		//Solo para simular que tengo el metodo comparar.
		Node<T> node_data = Node<T>(data);
		Node<T>* node_list = this -> search_element(pos);

		while( pos < size_ && node_list -> compare_to(node_data)){
			node_list = this -> search_element(++pos);
		}
		//Si hay coincidencia, es 0! 0 => false.
		if(!(node_list -> compare_to(node_data))){
			this -> erase(pos);
		} 

	}

	//8. Lo mismo pero que borre todas las ocurrencias.
	void erase_data_all_ocurrencies(const T& data){
		int pos = 1;
		//Solo para simular que tengo el metodo comparar.
		Node<T> node_data = Node<T>(data);
		Node<T>* node_list = this -> search_element(pos);
		List<int> positions;

		while( pos <= size_ ){
			if(!(node_list -> compare_to(node_data)))
				positions.push_front(pos);

			node_list = this -> search_element(++pos);
		}
		//Si hay coincidencia, es 0! 0 => false.
		while(!positions.empty()){
			//Primero saco los ultimos para que las posiciones de las ocurrencias no cambien
			this -> erase(positions.pop_front()); 
		} 

	}

	//9. Recibe una lista B por paramentro. Retornar una lista NUEVA con los valores A-B
	List<T>* substract(List<T> list){
		int pos = 1;
		//Solo para simular que tengo el metodo comparar.
		Node<T> node_data = Node<T>(list[pos]);
		Node<T>* node_list = this -> search_element(pos);
		List<T>* new_list = new List<T>();

		int i = 1;
		while( i <= size_ ){
			if(node_list -> compare_to(node_data))
				new_list -> push_back((*this)[i]);
			node_list = this -> search_element(++i);
		}			
		while( pos <= list.size() ){
			new_list -> erase_data_all_ocurrencies(list[++pos]);
		}

		return new_list;
	}

};	

#endif
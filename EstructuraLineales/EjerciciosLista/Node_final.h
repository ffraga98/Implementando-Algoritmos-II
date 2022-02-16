#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
	T data;
	Node<T> * next;
public:
	Node(const T& data){
		next = nullptr;
		setData(data);
	}
	
	Node(const Node<T>& rhs){
		*(this) = rhs;
	}

	void setData(const T& data) {
		this -> data = data;
	}

	void setNext(Node<T>* next) {
		this -> next = next;
	}

	const T& getData() const {
		return data;
	}
	
	Node<T>* getNext() const {
		return next;
	}

	Node<T>& operator=(const Node<T>& rhs){
		data = rhs.getData();
		next = rhs.getNext();
		return *this;
	}

	//Metodo usado para simular el comparar del final.
	int compare_to(const Node<T>& rhs){
		int res = 0;
		if(data > rhs.getData()){
			res = 1;
		}else if( data < rhs.getData()){
			res = -1;
		}
		return res;

	}

};

#endif
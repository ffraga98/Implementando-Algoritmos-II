#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
	T data_;
	Node<T>* previous_;
	Node<T>* next_;
public:
	Node(const T& data) : data_(data), previous_(nullptr), next_(nullptr){}
	
	Node(const Node<T>& rhs){
		*(this) = rhs;
	}

	void setData(const T& data) {
		data_ = data;
	}

	void setPrevious(Node<T>* previous) {
		previous_ = previous;
	}
	void setNext(Node<T>* next) {
		next_ = next;
	}

	const T& getData() const {
		return data_;
	}
	
	Node<T>* getNext() const {
		return next_;
	}
	
	Node<T>* getPrevious() {
		return previous_;
	}

	Node<T>& operator=(const Node<T>& rhs){
		data_ = rhs.getData();
		previous_ = rhs.getPrevious();
		next_ = rhs.getNext();
		return *this;
	}

};

#endif
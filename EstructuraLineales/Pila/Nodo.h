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

};
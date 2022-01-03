#include <iostream>
#include "Pila.h"
using namespace std;

int main(){
	Stack<int> pila;
	pila.push(1);
	pila.push(2);
	pila.push(3);

	cout << pila.pop() << endl;
	cout << pila.pop() << endl;
	cout << pila.pop() << endl;
	cout << pila.pop() << endl;

	return 0;
}
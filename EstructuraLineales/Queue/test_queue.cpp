#include <iostream>
#include "Queue.h"

int main(){
	Queue<std::string> cola;

	cola.push_back("Who do you need?");
	cola.push_back("Who do you love?");
	cola.push_back("When you come undone?");

	std::cout << cola.size() << std::endl;
	
	std::cout << cola.front() << std::endl;
	cola.pop_front();
	std::cout << cola.size() << std::endl;
	
	std::cout << cola.front() << std::endl;
	cola.pop_front();
	std::cout << cola.size() << std::endl;

	std::cout << cola.front() << std::endl;
	cola.pop_front();	
	std::cout << cola.size() << std::endl;
}
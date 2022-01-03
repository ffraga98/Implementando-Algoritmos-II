#ifndef STACK_EMPTY_EXCEPTION
#define STACK_EMPTY_EXCEPTION

#include <exception>

const char* ERROR = "Empty stack.";

class StackEmptyException: public std::exception {
public:
	const char * what() const throw() override;
private: 
	const char* exception_msg = ERROR;
};

#endif 

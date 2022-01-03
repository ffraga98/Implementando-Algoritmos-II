#include "StackEmptyException.h"

const char* StackEmptyException::what() const throw(){
	return exception_msg;
}
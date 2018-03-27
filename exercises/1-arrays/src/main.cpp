#include <iostream>
#include <cstdlib>
#include "lib/array.hpp"

int main(){
	Array* a = new Array(2);
	std::cout << a->getArray() << std::endl;
	delete a;
	
	return 0;
}
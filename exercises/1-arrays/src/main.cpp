#include <iostream>
#include <cstdlib>
#include "../lib/array.hpp"

int main(){
    array<int> *a = new array<int>();
    for(int i=0; i<20; ++i){
    	a->push(i);
    }
    
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    a->insert(5, 55);
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    a->insert(0, 13);
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    a->insert(0, 22);
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    try{
    	a->insert(33, 131);
    }catch (const std::exception& e) {
        std::cout << e.what() << "\n\n";
    }
    
    a->prepend(51);
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    std::cout << a->pop() << std::endl;
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    a->del(0);
    a->del(0);
    a->del(0);
    a->del(5);
    a->del(18);
    try{
    	a->del(18);
    }catch(const std::exception& e){
    	std::cout << e.what() << "\n\n";
    }
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    a->prepend(51);
    a->prepend(51);
    a->insert(6,51);
    a->insert(7,51);
    a->push(51);
    a->push(51);
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    std::cout << a->rem(51) << std::endl;
    a->print();
    std::cout << "size: " << a->size() << std::endl;
    std::cout << "index: " << a->cap() << std::endl << std::endl;
    
    std::cout << a->find(19) << "\n\n";
    
    
    
    
    delete a;
	return 0;
}
//5 9
//0 1 2 3 4 5 6 7 8 9
//0 1 2 3 4 9 5 6 7 8 9
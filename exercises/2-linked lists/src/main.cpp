#include <iostream>
#include <cstdlib>
#include "../lib/list.hpp"

int main(){
    list<int>* a = new list<int>();
    for(int i=1; i<=100000; ++i){
        a->push_back(i);
    }
    a->push_back(13);
    a->push_front(13);
    a->print();
    std::cout << a->pop_back() << "\n";
    std::cout << a->pop_front() << "\n";
    std::cout << a->back() << "\n";
    std::cout << a->front() << "\n";
    a->print();
    
    a->insert(0, 13);
    a->print();
    std::cout << a->erase(0) << std::endl;
    std::cout << a->erase(9) << std::endl;
    std::cout << a->erase(3) << std::endl;
    a->print();
    std::cout << a->value_of_n(0) << std::endl;
    std::cout << a->value_of_n(3) << std::endl;
    a->remove_value(9);
    a->print();
    a->reverse();
    a->print();
    
    list<int>* b = new list<int>();
    b->push_back(1);
    b->push_back(2);
    std::cout << "B1: ";
    b->print();
    b->reverse();
    std::cout << "B2: ";
    b->print();
    delete a;
    delete b;
}


#include <iostream>
#include <cstdlib>
#include "../lib/list.hpp"

int main(){
    node<int>* a = new node<int>;
    a->value = 1;
    std::cout << a->value;
}
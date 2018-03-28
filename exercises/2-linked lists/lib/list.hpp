#ifndef LIST_H
#define LIST_H

#include <cstring>
#include <stdexcept>

template <class T>
struct node{
	node* next;
	T value;
};

template <class T> 
class list
{
public:
	list(){
		_tail = new node<T>;
		_size = 0;
	};
	
	~list(){
		
	};
	
	unsigned int size(){
		return _size;
	};
	
	bool empty(){
		return _size == 0 ? true : false; 
	};
	
	T value_at(unsigned int index){
		
	};
	
	void push_front(T value){
		
	};
	
	T pop_front(){
		
	};
	
	void push_back(T value){
		
	};
	
	T pop_back(){
		
	};
	
	T front(){
		
	};
	
	T back(){
		
	};
	
	void insert(unsigned int index, T value){
		
	};
	
	void erase(unsigned int index){
		
	};
	
	T value_of_n(unsigned int n){
		
	};
	
	void reverse(){
		
	};
	
	unsigned int remove_value(T value){
		
	};

private:
	node<T>* _tail;
	unsigned int _size;
};

#endif //LIST_H
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
		_tail->next = _tail;
		
		_size = 0;
	};
	
	~list(){
		while(_size > 0){
			pop_back();
		}
		delete _tail;
	};
	
	unsigned int size(){
		return _size;
	};
	
	bool empty(){
		return _size == 0 ? true : false; 
	};
	
	T value_at(unsigned int index){
		node<T>* aux = _tail->next;
		for(int i=0; i<=index; ++i){
			aux = aux->next;
		}
		return aux->value;
	};
	
	void push_back(T value){
		node<T>* back = new node<T>;
		back->next = _tail->next;
		back->value = value;
		_tail->next = back;
		++_size;
	};
	
	T pop_back(){
		node<T>* aux = _tail->next->next;
		T value = _tail->next->value;
		delete _tail->next;
		_tail->next = aux;
		--_size;
		return value;
	};
	
	void push_front(T value){
		node<T>* aux = _tail->next;
		while(aux->next != _tail){
			aux = aux->next;
		}
		node<T>* front = new node<T>;
		front->next = aux->next;
		front->value = value;
		aux->next = front;
		++_size;
	};
	
	T pop_front(){
		node<T>* last = _tail;
		node<T>* aux = _tail->next;
		while(aux->next != _tail){
			aux = aux->next;
			last = last->next;
		}
		T value = aux->value;
		last->next = aux->next;
		delete aux;
		--_size;
		return value;
	};
	
	T front(){
		node<T>* aux = _tail->next;
		while(aux->next != _tail){
			aux = aux->next;
		}
		return aux->value;
	};
	
	T back(){
		return _tail->next->value;
	};
	
	void insert(unsigned int index, T value){
		node<T>* aux = _tail;
		for(int i=0; i<index; ++i){
			aux = aux->next;
		}
		node<T>* insert = new node<T>;
		insert->value = value;
		insert->next = aux->next;
		aux->next = insert;
		++_size;
	};
	
	T erase(unsigned int index){
		node<T>* last = _tail;
		node<T>* aux = _tail->next;
		for(int i=0; i<index; ++i){
			aux = aux->next;
			last = last->next;
		}
		T value = aux->value;
		last->next = aux->next;
		delete aux;
		--_size;
		return value;
	};
	
	T value_of_n(unsigned int n){
		node<T>* aux = _tail->next;
		for(int i=0; i<_size-n-1; ++i){
			aux = aux->next;
		}
		return aux->value;
	};
	
	//invert all next pointers
	void reverse(){
		node<T>* last_aux = _tail;
		node<T>* aux = _tail->next;
		node<T>* next_aux = aux->next;
		for(int i=0; i<_size+1; ++i){
			aux->next = last_aux;
			last_aux = aux;
			aux = next_aux;
			next_aux = next_aux->next;
		}
	};
	
    void remove_value(T value){
		node<T>* last = _tail;
		node<T>* aux = _tail->next;
		while(aux->value != value){
			last = last->next;
			aux = aux->next;
			if(aux == _tail){
				return;				
			}
		}
		last->next = aux->next;
		delete aux;
		--_size;
	};
	
	void print(){
		node<T>* aux = _tail->next;
		do{
			std::cout << aux->value << " ";
			aux = aux->next;
		}while(aux != _tail);
		std::cout << "\n";
	};

private:
	node<T>* _tail;
	unsigned int _size;
};

#endif //LIST_H
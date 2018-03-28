#ifndef ARRAY_H
#define ARRAY_H

#include <cstring>
#include <stdexcept>

template <class T> 
class array
{
public:
	array() : array(16){
	};

	array(unsigned int cap){
		_cap = cap;
		_size = 0;
		if(_cap > 0){
			_data = new T[_cap];
		}
	};
	
	~array(){
		delete[] _data;	
	};
	
	unsigned int size(){
		return _size;
	};
	
	unsigned int cap(){
		return _cap;
	};
	
	bool isEmpty(){
		return _size = 0 ? true : false;
	};
	
	T at(unsigned int index){
		if(index < _size){
			return _data[index];
		}else{
			throw std::runtime_error("bad index");
		}
	};
	
	void push(const T element){
		if(_size == _cap)
			_resize();
			
		_data[_size] = element;
		++_size;
	};
	
	void insert(unsigned int index, const T element){
		if(_size == _cap)
			_resize();
		if(index < _size){
			memmove(_data+index+1, _data+index, sizeof(T)*(_size-index));
			++_size;
			_data[index] = element;
		}else if(index == _size){
			_data[index] = element;
			++_size;
		}else{
			throw std::runtime_error("bad index");
		}
	};
	
	void prepend(const T item){
		insert(0, item);	
	};
	
	T pop(){
		if(_size > 0){
			--_size;
			return _data[_size+1];
		}else{
			throw std::runtime_error("empty array");
		}
	};
	
	void del(unsigned int index){
		if(index < _size){
			memmove(_data+index, _data+index+1, sizeof(T)*_size-1-index);
			--_size;
		}else if(index == _size-1){
			--_size;
		}else{
			throw std::runtime_error("bad index");
		}
	}
	
	//return # of elements removed
	unsigned int rem(const T item){
		unsigned int removed = 0;
		for(int i=0; i<_size; ++i){
			if(_data[i] == item){
				++removed;
				del(i);
				--i;
			}
		}
		return removed;
	};
	
	long int find(const T item){
		for(unsigned int i=0; i<_size; ++i){
			if(_data[i] == item){
				return i;
			}
		}
		return -1;
	}
	
	void print(){
		for(unsigned int i=0; i<_size; ++i){
			std::cout << _data[i] << " ";
		}
		std::cout << std::endl;
	};
	
private:
	T  *_data;
	unsigned int _size;
	unsigned int _cap;
	
	void _resize(){
		T* aux = new T[_cap];
		memcpy(aux, _data, sizeof(T)*_cap);
		_cap*=2;
		delete[] _data;
		_data = new T[_cap];
		memcpy(_data, aux, sizeof(T)*_cap/2);
		delete[] aux;
	}
};

#endif //ARRAY_H
#pragma once
template<typename T>
class DM
	//Dynamic Memory
{
public:
	int size = 0;
	T* Object;
	DM() {
		Object = new T[size];
	}
	void Add(T entity) {
		T* temp = Object;		
		Object = new T[size];
		Object = temp;
		Object[size] = entity;
		size++;
	}
};


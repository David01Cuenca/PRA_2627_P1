#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"
#include <ostream>
#include <stdexcept>
#include <iostream>

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr; //Array
		int max; //Tamaño maximo del array
		int n; //Numero de elementos actuales
		static const int MINSIZE = 2;
		void resize(int new_size);
		void size_adjuster();
	public:
		ListArray():arr(new T[MINSIZE]), max(MINSIZE), n(0){};
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out,ListArray<T> &list){
		out << "[";
		for(int i = 0; i < list.n; i++){
			out << list.arr[i];
			if(i < list.n - 1) out << ", ";
		}
			return out << "]";
		}
		void insert(int pos, T e) override;
                void append(T e) override;
                void prepend(T e) override;
                T remove(int pos) override;
                T get(int pos) override;
                int search(T e) override;
                bool empty() override;
                int size() override;
		~ListArray() override;
};

template <typename T>
ListArray<T>::~ListArray(){
	delete[] arr;
}

//get para el operador []
template <typename T>
T ListArray<T>::operator[](int pos){
	return get(pos);
}

template <typename T>
void ListArray<T>::insert(int pos, T e) {
	if(pos < 0 || pos > n){
		throw std::out_of_range("¡Posición inválida!");
	}
	size_adjuster();
	for(int i = n; i > pos; i--){
		arr[i] = arr[i-1];
	}
	arr[pos]=e;
	n++;
}

template <typename T>
void ListArray<T>::append(T e){
	insert(n,e);
}

template <typename T>
void ListArray<T>::prepend(T e){
	insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
	if(pos < 0 || pos >= n){
		throw std::out_of_range("¡Posición invalida!");
	}	
	T d_elem = arr[pos];                   // guardamos el valor antes de pisarlo
	for(int i = pos; i < n - 1; i++){      // de izquierda a derecha
		arr[i] = arr[i+1];
	}
	n--;                                   // lo que queda en arr[n] ya no cuenta
	size_adjuster();                       // si sobra mucho espacio, reduce
	return d_elem;
}
//Funcion encargada de decir que tamaño es el ideal para x situacion.
template <typename T>
void ListArray<T>::size_adjuster(){
	if(n==max){
		resize(max*2);
	} else if(n < max/4 && max/2 >= MINSIZE){
		resize(max/2);
	}
}

//Requiere que el new_size esta ya modificado segun los requerimientos de expansión o reducción
template <typename T>
void ListArray<T>::resize(int new_size){
	T* aux_arr = new T[new_size];
	for(int i = 0; i < n; i++){
		aux_arr[i] = arr[i];
	}
	delete[] arr;
	max=new_size;
	arr=aux_arr;
}

template <typename T>
T ListArray<T>::get(int pos) {
	if(pos < 0 || pos > n){
		throw std::out_of_range("¡Posición invalida!");
	}
	return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e){
	for(int i = 0; i < n; i++){            // solo hasta n, lo demás es basura
		if(arr[i] == e){
			return i;
		}
	}
	return -1;
}

template <typename T>
bool ListArray<T>::empty() {
	if(n>0){
		return false;
	} else {
		return true;
	}
}

template <typename T>
int ListArray<T>::size() {
	return n;
}

#endif

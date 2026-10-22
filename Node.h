#ifndef NODE_H
#define NODE_H
#include "List.h"
#include <ostream>

template <typename T>
class Node : public List<T>{
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>* next=nullptr):data(data){};
		friend std::ostream& operator<< (std::ostream &out, const Node<T> &node){
			return out << node.data;
		}
};


#endif


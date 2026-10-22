#include "List.h"
#include <ostream>
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size);
	public:
		ListArray():arr(new T[MINSIZE]), n(0), max(MINSIZE){};
		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out,ListArray<T> &list){
			return out;
		}
		void insert(int pos, T e);
                void append(T e);
                void prepend(T e);
                T remove(int pos);
                T get(int pos);
                int search(T e);
                bool empty();
                int size();
		~ListArray() override;
};

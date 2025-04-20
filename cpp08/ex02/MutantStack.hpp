#pragma once

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack {

public:

	struct iterator {

		iterator(T *ptr): _ptr(ptr) {}


		private:
			T *_ptr;
	};

	MutantStack() : std::stack() {}
	MutantStack( MutantStack& obj ): std::stack(obj) {}
	MutantStack& operator=( const MutantStack& obj ) {
		//
	}
	~MutantStack() {};

private:

};
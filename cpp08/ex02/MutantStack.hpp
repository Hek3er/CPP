#pragma once

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:

	MutantStack() : std::stack<T>() {}
	MutantStack( MutantStack& obj ): std::stack<T>(obj) {}
	MutantStack& operator=( const MutantStack& obj ) {
		if (this != &obj) {
			std::stack<T>::operator=(obj);
		}
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	~MutantStack() {};

private:

};
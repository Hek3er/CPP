#include "Span.hpp"

Span::Span( const size_t size ) :  _size(size) {

}

Span::Span( const Span& obj ) : _arr(obj._arr), _size(obj._size) {

}

Span& Span::operator=( const Span& obj ) {
	if (this != &obj) {
		_arr = obj._arr;
	}
	return (*this);
}

void	Span::addNumber( const int val ) {
	if (this->_arr.size() == this->_size) {
		throw std::out_of_range("Span is Full");
	}
	this->_arr.push_back(val);
}

int		Span::shortestSpan( void ) {
	std::sort(_arr.begin(), _arr.end());
	if (this->_arr.size() <= 1) {
		throw std::runtime_error("span is empty or have 1 element");
	}
	int min = INT_MAX;
	for (size_t i = 0; i < _arr.size() - 1; i++) {
		min = std::min(abs(_arr[i] - _arr[i + 1]), min);
	}
	return min;
}
int		Span::longestSpan( void ) {
	std::sort(_arr.begin(), _arr.end());
	if (this->_arr.size() <= 1) {
		throw std::runtime_error("span is empty or have 1 element");
	}
	return (std::abs(this->_arr[this->_arr.size() - 1] - this->_arr[0]));
}

Span::~Span() {
}


#include "Span.hpp"

int main() {

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(2);
	} catch(std::exception& e ) {
		std::cout << "[ " << __LINE__ << " ]  exception caught : " << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	Span t = Span(1);
	t.addNumber(2);
	try {
		t.longestSpan();
	}  catch(std::exception& e ) {
		std::cout << "[ " << __LINE__ << " ]  exception caught : " << e.what() << std::endl;
	}

	try {
		t.shortestSpan();
	}  catch(std::exception& e ) {
		std::cout << "[ " << __LINE__ << " ]  exception caught : " << e.what() << std::endl;
	}


	Span big = Span(10000);

	srand(time(NULL));
	std::vector<int> tmp;
	tmp.push_back(0);
	// big.addNumber(0);
	for (int i = 1; i < 9998; i++) {
		tmp.push_back((rand() % INT_MAX) + 1);
	}
	tmp.push_back(INT_MAX);

	big.insert(tmp.begin(), tmp.end());

	try {
		std::cout << "longestSpan : " << big.longestSpan() << std::endl;
	}  catch(std::exception& e ) {
		std::cout << "[ " << __LINE__ << " ]  exception caught : " << e.what() << std::endl;
	}

	try {
		std::cout << "shortestSpan : " << big.shortestSpan() << std::endl;
	}  catch(std::exception& e ) {
		std::cout << "[ " << __LINE__ << " ]  exception caught : " << e.what() << std::endl;
	}


	return 0;


}

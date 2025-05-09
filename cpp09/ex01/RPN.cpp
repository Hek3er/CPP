#include "RPN.hpp"

RPN::RPN( char **av ) {
	this->_av = av;
}

RPN::RPN( RPN& obj ) {

	*this = obj;
}

RPN& RPN::operator=( const RPN& obj) {
	if (this != &obj) {
		this->_av = obj._av;
		this->_arguments = obj._arguments;
		this->_c = obj._c;
	}
	return (*this);
}

std::string RPN::CleanLine(std::string& line) const {
	std::string result;
	for (size_t i = 0; i < line.length(); i++) {
		if (!std::isspace(line[i])) {
			result += line[i];
		}
	}
	return result;
}

double RPN::ConvertDouble(const std::string& n) const {
	double res;
	std::stringstream out(n);
	out >> res;
	return res;
}

bool RPN::IsCharacterCorrect( const std::string& n) const {
	if (n.length() > 1 && n[0] != '-') {
		return false;
	}
	if (n[0] == '-' || n[0] == '+' || n[0] == '/' || n[0] == '*') {
		if (n[0] == '-' && n.length() > 2) {
			return false;
		} else if (n[0] == '-' && n.length() == 2 && n[1] >= '0' && n[1] <= '9') {
			return true;
		}
		return true;
	}
	if (n[0] >= '0' && n[0] <= '9') {
		return true;
	}
	return false;
}

void	RPN::Run( ) {

	size_t pos = 0;
	double a = 0;
	double b = 0;
	double result = 0;

	for (size_t i = 1; _av[i] != NULL; i++) {
		std::string str(_av[i]);
		while ((pos = str.find(" ")) != std::string::npos) {
			std::string sub = str.substr(0, pos);
			sub = CleanLine(sub);
			if (!sub.empty()) {
				if (!IsCharacterCorrect(sub)) {
					std::cerr << "Error '" << sub << "'" << std::endl;
					return ;
				}
				this->_arguments.push_back(sub);
			}
			str.erase(0, pos + 1);
		}
		CleanLine(str);
		if (!IsCharacterCorrect(str)) {
			std::cerr << "Error '" << str << "'" << std::endl;
			return ;
		}
		if (str.empty()) {
			std::cerr << "Error: empty string" << std::endl;
			return ;
		}
		else {
			this->_arguments.push_back(str);
		}
	}

	for (std::list<std::string>::iterator it = _arguments.begin(); it != _arguments.end(); it++) {
		if (*it != "*" && *it != "+" && *it != "-" && *it != "/") {
			double number = ConvertDouble(*it);
			this->_c.push(number);
		}
		else {
			if (this->_c.size() > 1) {
				a = this->_c.top();
				this->_c.pop();
				b = this->_c.top();
				this->_c.pop();
				if (*it == "*") {
					result = a * b;
				} else if (*it == "+") {
					result = a + b;
				} else if (*it == "-") {
					result = b - a;
				} else if (*it == "/") {
					if (a != 0)
						result = b / a;
					else {
						std::cout << "Error: Invalid Operation"<< std::endl;
						return ;
					}
				}
				this->_c.push(result);
			} else {
				std::cout << "Error: Invalid Operation" << std::endl;
				return;
			}
		}
	}
	if (this->_c.size() == 1) {
		std::cout << this->_c.top() << std::endl;
	} else {
		std::cout << "Error: Invalid Operation" << std::endl;
		return;
	}
}

RPN::~RPN() {
}


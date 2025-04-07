#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter( ScalarConverter& obj ) {
	(void)obj;
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& obj) {
	(void)obj;
	return (*this);
}

bool	CheckCharacters( const std::string str, const std::string allowed ) {
	for (size_t i = 0; i < str.length(); i++) {
		if ((str[i] == '.' && (i + 1 == str.length())) || (str[i] == '.' && !isdigit(str[i + 1]))) {
			return false;
		}
		if ( allowed.find(str[i]) == std::string::npos ) {
			return false;
		}
	}
	return true;
}

void	handle_int( const std::string str ) {
	std::stringstream ss(str);
	int out;
	ss >> out;
	if (ss.fail()) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible (overflow)", "");
		PRINT_FLOAT("impossible", "");
		PRINT_DOUBLE("impossible", "");
		return ;
	}
	if (out >= 32 && out <= 126) {
		PRINT_CHAR(static_cast<char>(out), "");
	} else {
		PRINT_CHAR("Non Displayable", "");
	}
	PRINT_INT(out, "");
	PRINT_FLOAT(static_cast<float>(out), ".0f");
	PRINT_DOUBLE(static_cast<double>(out), ".0");
}

bool isNaN( double n ) {
	return n != n;
}

bool isNaN( float n ) {
	return n != n;
}

bool isInf( double n ) {
	return n == std::numeric_limits<double>::infinity() || n == -std::numeric_limits<double>::infinity();
}

bool isInf( float n ) {
	return n == std::numeric_limits<float>::infinity() || n == -std::numeric_limits<float>::infinity();
}

void	handle_double( const std::string str ) {
	std::stringstream ss(str);
	double out;
	ss >> out;
	if (ss.fail()) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible", "");
		PRINT_FLOAT("impossible", "");
		PRINT_DOUBLE("impossible", "");
		return ;
	}
	if (isNaN(out)) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible", "");
		PRINT_FLOAT(static_cast<float>(out), "f");
		PRINT_DOUBLE(out, "");
		return ;
	}
	if (isInf(out)) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible", "");
		PRINT_FLOAT(static_cast<float>(out), "f");
		PRINT_DOUBLE(out, "");
		return ;
	}
	if (static_cast<int>(out) >= 32 && static_cast<int>(out) <= 126) {
		PRINT_CHAR(static_cast<char>(out), "");
	} else {
		PRINT_CHAR("Not Displayable", "");
	}
	if (out > INT_MAX || out < INT_MIN) {
		PRINT_INT("Impossible", "");
	} else {
		PRINT_INT(static_cast<int>(out), "");
	}
	if (out > std::numeric_limits<float>::max() || out < -std::numeric_limits<float>::max() || 
    (out != 0.0 && out > -std::numeric_limits<float>::min() && out < std::numeric_limits<float>::min())) {
		PRINT_FLOAT("Impossible", "");
	} else {
		if (static_cast<long long>(out) == out){
			PRINT_FLOAT(static_cast<float>(out), ".0f");
		}
		else {
			PRINT_FLOAT(static_cast<float>(out), "f")
		}
	}
	if (static_cast<long long>(out) == out){
		PRINT_DOUBLE(out, ".0");
	}
	else {
		PRINT_DOUBLE(out , "")
	}
}

void	handle_float( const std::string str ) {
	std::stringstream ss(str);
	float out;
	ss >> out;
	if (ss.fail()) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible", "");
		PRINT_FLOAT("impossible", "");
		PRINT_DOUBLE("impossible", "");
		return ;
	}
	if (isNaN(out)) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible", "");
		PRINT_FLOAT(out, "f");
		PRINT_DOUBLE(static_cast<double>(out), "");
		return ;
	}
	if (isInf(out)) {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible", "");
		PRINT_FLOAT(out, "f");
		PRINT_DOUBLE(static_cast<double>(out), "");
		return ;
	}
	if (static_cast<int>(out) >= 32 && static_cast<int>(out) <= 126) {
		PRINT_CHAR(static_cast<char>(out), "");
	} else {
		PRINT_CHAR("Not Displayable", "");
	}
	if (out > INT_MAX || out < INT_MIN) {
		PRINT_INT("Impossible", "");
	} else {
		PRINT_INT(static_cast<int>(out), "");
	}
	if (out == static_cast<long long>(out)) {
		PRINT_FLOAT(out, ".0f");
		PRINT_DOUBLE(out, ".0");
	} else {
		PRINT_FLOAT(out, "f");
		PRINT_DOUBLE(out, "");
	}
}

void	handle_char( const std::string str ) {
	std::stringstream ss(str);
	char out;
	ss >> out;
	if (ss.fail() && str[0] != ' ') {
		PRINT_CHAR("impossible", "");
		PRINT_INT("impossible (overflow)", "");
		PRINT_FLOAT("impossible", "");
		PRINT_DOUBLE("impossible", "");
		return;
	}
	if (str[0] == ' ') {
		out = ' ';
	}
	PRINT_CHAR(out, "");
	PRINT_INT(static_cast<int>(out), "");
	PRINT_FLOAT(static_cast<float>(out), ".0f");
	PRINT_DOUBLE(static_cast<double>(out), ".0");
}

void	ScalarConverter::convert( const std::string &str ) {
	if (str.empty()) {
		std::cout << "Usage:\n\t./convert <arg>" << std::endl;
		return ;
	}
	// handle int
	if (CheckCharacters(str, "1234567890+-")) {
		if (((str[0] == '-' || str[0] == '+') && !str[1]) || !CheckCharacters(str.substr(1), "1234567890")) {
			std::cout << "Invalid Type" << std::endl;
			return ;
		}
		std::cout << "Type: <Int>" << std::endl;
		handle_int(str);
		return ;
	}
	//handle double
	if (CheckCharacters(str, "1234567890-+.") || str == "nan" || str == "+inf" || str == "-inf") {
		if ( ( str != "nan" && str != "+inf" && str != "-inf" && !CheckCharacters(str.substr(1), "1234567890.")) || ((str[0] == '-' || str[0] == '+') && (str != "nan" && str != "+inf" && str != "-inf") && (!str[1] || !isdigit(str[1])))) {
			std::cout << "Invalid Type" << std::endl;
			return ;
		}
		std::cout << "Type: <Double> " << std::endl;
		handle_double(str);
		return ;
	}
	//handle float
 	if ((CheckCharacters(str, "1234567890-+.f") && str[0] != 'f'  && str[str.length() - 1] == 'f' && isdigit(str[str.length() - 2])) || str == "nanf" || str == "+inff" || str == "-inff") {
		if ((str != "nanf" && str != "+inff" && str != "-inff" &&!CheckCharacters(str.substr(1), "1234567890.f")) || ((str[0] == '-' || str[0] == '+')  && (str != "nanf" && str != "+inff" && str != "-inff") && (!str[1] || !isdigit(str[1])))) {
			std::cout << "Invalid Type" << std::endl;
			return ;
		}
		if ((str != "nanf" && str != "+inff" && str != "-inff" && str.find('.') == std::string::npos)) {
			std::cout << "Invalid Type" << std::endl;
			return ;
		}
		std::string new_str = str.substr(0, str.length() - 1);
		std::cout << "Type: <Float>" << std::endl;
		handle_float(new_str);
		return ;
	}
	//handle char
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126) {
		std::cout << "Type: <Char>" << std::endl;
		handle_char(str);
		return ;
	}
	std::cout << "Invalid Type" << std::endl;

}

ScalarConverter::~ScalarConverter() {
	std::cout << "Deconstructor Called" << std::endl;
}

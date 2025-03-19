#include "ScalarConverter.hpp"

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

void	handle_double( const std::string str ) {
	if (str == "nan") {
		
	}
}

void	ScalarConverter::convert( const std::string &str ) {
	if (str.empty()) {
		std::cerr << "Usage:\n\t./convert <arg>" << std::endl;
		return ;
	}
	// handle int
	if (CheckCharacters(str, "1234567890+-")) {
		if ((str[0] == '-' || str[0] == '+') && !str[1]) {
			std::cerr << "Invalid Type" << std::endl;
			return ;
		}
		handle_int(str);
		return ;
	}
	//handle double
	if (CheckCharacters(str, "1234567890-+.") || str == "nan" || str == "+inf" || str == "-inf") {
		if ((str[0] == '-' || str[0] == '+') && (str != "nan" && str != "+inf" && str != "-inf") && (!str[1] || !isdigit(str[1]))) {
			std::cerr << "Invalid Type" << std::endl;
			return ;
		}
		std::cout << "double " << std::endl;
		return ;
	}
	//handle float
 	if ((CheckCharacters(str, "1234567890-+.f") && str[0] != 'f'  && str[str.length() - 1] == 'f') || str == "nanf" || str == "+inff" || str == "-inff") {
		if ((str[0] == '-' || str[0] == '+')  && (str != "nanf" && str != "+inff" && str != "-inff") && (!str[1] || !isdigit(str[1]))) {
			std::cerr << "Invalid Type" << std::endl;
			return ;
		}
		std::cout << "Float" << std::endl;
		return ;
	}
	//handle char
	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126) {
		std::cout << "Char" << std::endl;
		return ;
	}
	std::cerr << "Invalid Type" << std::endl;

}

ScalarConverter::~ScalarConverter() {
	std::cout << "Deconstructor Called" << std::endl;
}


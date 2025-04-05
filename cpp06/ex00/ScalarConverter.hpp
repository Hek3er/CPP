#pragma once

# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits.h>

#define PRINT_INT(x, y) std::cout << "int: " << x << y << std::endl;
#define PRINT_CHAR(x, y) std::cout << "char: '" << x << y << "'"<< std::endl;
#define PRINT_DOUBLE(x, y) std::cout << "double: " << x << y << std::endl;
#define PRINT_FLOAT(x, y) std::cout << "float: " << x << y << std::endl;

class ScalarConverter {

public:

	ScalarConverter();
	ScalarConverter( ScalarConverter& obj );
	ScalarConverter& operator=( const ScalarConverter& obj );
	static void convert( const std::string &str );
	~ScalarConverter();

private:

};
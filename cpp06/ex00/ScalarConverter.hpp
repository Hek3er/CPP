#pragma once

# include <iostream>

class ScalarConverter {

public:

~ScalarConverter();
static void	convert( const std::string &str );

private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter& obj );
	ScalarConverter& operator=( const ScalarConverter& obj );

};
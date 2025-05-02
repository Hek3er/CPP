#pragma once

# include <iostream>
# include <stack> 
# include <list>
# include <sstream>

class RPN {

public:

	RPN( char **av );
	RPN( RPN& obj );
	RPN& operator=( const RPN& obj );
	void	Run(  );
	~RPN();

private:
	std::stack<int> 		_c;
	std::list<std::string>  _arguments;
	char**					_av;
	std::string CleanLine(std::string& line) const;
	int 		ConvertInt(const std::string& n) const;
	bool		IsCharacterCorrect( const std::string& n) const;
};
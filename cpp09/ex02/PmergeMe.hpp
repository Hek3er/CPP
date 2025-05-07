#pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <sstream>

class PmergeMe {

public:

	PmergeMe( char ** av );
	PmergeMe( PmergeMe& obj );
	PmergeMe& operator=( const PmergeMe& obj );
	void	Run( void );
	void	SortV( std::vector<int>& arr );
	void	SortDq( std::deque<int>& arr );
	~PmergeMe();
	
private:
	char**	 _av;
	std::vector<int> _vec;
	std::deque<int> _dq;
	std::string CleanLine(std::string& line) const;
	int ConvertInt(const std::string& n) const;
	bool IsCharacterCorrect( const std::string& n) const;
	std::vector<int> GetJacobSequence( const size_t &size ) const;
};
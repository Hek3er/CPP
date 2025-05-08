#pragma once

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <ctime>

class BitcoinExchange {

public:

	BitcoinExchange( const std::string& filename );
	BitcoinExchange( const BitcoinExchange& obj );
	BitcoinExchange& operator=( const BitcoinExchange& obj );
	void run();
	~BitcoinExchange();

private:
	std::string _filename;
	std::string _error_log;
	std::map<size_t, double> _exchange_db;

	void		ParseInput();
	void		ParseDB();
	bool		IsLeapYear( int year ) const;
	int		IsDateCorrect(std::string date);
	std::string CleanLine(std::string& line) const;
	int			ConvertInt( const std::string& n) const;
	double		ConvertDouble( const std::string& n) const;
	size_t		ConvertDate(std::string date) const;
};
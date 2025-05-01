#pragma once

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange {

public:

	BitcoinExchange( const std::string& filename );
	BitcoinExchange( const BitcoinExchange& obj );
	BitcoinExchange& operator=( const BitcoinExchange& obj );
	void run();
	~BitcoinExchange();

private:
	std::string _filename;
	std::map<size_t, double> _exchange_db;
	std::map<size_t, int> _value_db;

	void	ParseInput();
	void	ParseDB();
	int		ConvertInt( const std::string& n) const;
	double		ConvertDouble( const std::string& n) const;
	size_t		ConvertDate(std::string date) const;
};
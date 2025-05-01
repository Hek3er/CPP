#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( const std::string& filename ) {
	this->_filename = filename;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& obj ) {

	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& obj) {
	if (this != &obj) {
		this->_filename = obj._filename;
	}
	return (*this);
}

void	BitcoinExchange::run() {
	ParseDB();
	for (auto &a : this->_exchange_db) {
		std::cout << a.first << " -> " << a.second << std::endl;
	}
}


int BitcoinExchange::ConvertInt(const std::string& n) const {
	int res;
	std::stringstream out(n);
	out >> res;
	return res;
}

double BitcoinExchange::ConvertDouble(const std::string& n) const {
	double res;
	std::stringstream out(n);
	out >> res;
	return res;
}

size_t BitcoinExchange::ConvertDate( std::string date ) const {
	//y-m-d => y * 1000 + m * 100 + d
	size_t pos = 0;
	size_t result = 0;
	int		factor = 1000;
	while ((pos = date.find("-")) != std::string::npos) {
		std::string element = date.substr(0, pos);
		date.erase(0, pos + 1);
		result += ConvertInt(element) * factor;
		factor /= 10;
		if (factor == 10) {
			result += ConvertInt(date);
		}
	}
	return result;
}

void BitcoinExchange::ParseInput() {
	std::ifstream file(this->_filename);
	if (file.fail() || !file.is_open()) {
		throw std::runtime_error("Failed To open file " + this->_filename);
	}


}

void BitcoinExchange::ParseDB() {
	std::ifstream file("data.csv");
	if (file.fail() || !file.is_open()) {
		throw std::runtime_error("Failed To open database");
	}
	std::string line;
	while (std::getline(file, line)) {
		if (line == "date,exchange_rate") {
			continue;
		}
		std::string date_str = line.substr(0, line.find(","));
		line.erase(0, line.find(",") + 1);
		int date = ConvertDate(date_str);
		double exchange_rate = ConvertDouble(line);
		_exchange_db[date] = exchange_rate;
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange() {
}


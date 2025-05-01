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
	ParseInput();
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

std::string BitcoinExchange::CleanLine(std::string& line) const {
	std::string result;
	for (size_t i = 0; i < line.length(); i++) {
		if (!std::isspace(line[i])) {
			result += line[i];
		}
	}
	return result;
}

int	BitcoinExchange::IsDateCorrect(std::string date) const {
	size_t pos = 0;
	size_t i = 0;
	std::string date_arr[3];

	while ((pos = date.find("-")) != std::string::npos) {
		std::string element = date.substr(0, pos);
		date.erase(0, pos + 1);
		date_arr[i++] = element;
	}
	date_arr[i] = date;
	if (date_arr[0].empty() || date_arr[1].empty() || date_arr[2].empty()){
		return -1;
	}

	int year = ConvertInt(date_arr[0]);
	int month = ConvertInt(date_arr[1]);
	int day = ConvertInt(date_arr[2]);

	std::time_t t = std::time(NULL);
	std::tm * time_info = std::localtime(&t);
	int currentYear = 1900 + time_info->tm_year; 

	if (year < 2009 || year > currentYear) return -1;
	if (month <= 0 || month > 12) return -1;
	if (day <= 0 || day > 31) return -1;
	
	return year * 1000 + month * 100 + day;
}

void BitcoinExchange::ParseInput() {
	std::ifstream file(this->_filename);
	if (file.fail() || !file.is_open()) {
		throw std::runtime_error("Failed To open file " + this->_filename);
	}
	std::string line;
	while (std::getline(file, line)) {
		size_t pos = line.find("|");
		if (pos == std::string::npos) {
			std::cout << "Error: '|' not found" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		line.erase(0, pos + 1);
		date = CleanLine(date);
		line = CleanLine(line);

		if (date == "date" && line == "value") {
			continue;
		}

		int key_date = IsDateCorrect(date);
		if (key_date == -1) {
			std::cout << "Error: '" << date << "' is incorrect" << std::endl;
			continue;
		}
		double value = ConvertDouble(line);
		if (value < 0 || value > 1000) {
			if (value < 0) {
				std::cout << "Error: Value should be positive" << std::endl;
			} else {
				std::cout << "Error: Value Too Big" << std::endl;
			}
			continue;
		}
		std::map<size_t, double>::iterator it = this->_exchange_db.lower_bound(key_date);
		if (it != _exchange_db.end()) {
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
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


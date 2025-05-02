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
	int		factor = 10000;
	while ((pos = date.find("-")) != std::string::npos) {
		std::string element = date.substr(0, pos);
		date.erase(0, pos + 1);
		result += ConvertInt(element) * factor;
		factor /= 100;
		if (factor == 1) {
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

bool BitcoinExchange::IsLeapYear( int year ) const {
	if (year % 400 == 0) {
		return true;
	} else if (year % 100 == 0) {
		return false;
	} else if (year % 4 == 0) {
		return true;
	}
	return false;
}

int	BitcoinExchange::IsDateCorrect(std::string date)  {
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
		this->_error_log  = "Date is invalid, should be y-m-d";
		return -1;
	}

	int year = ConvertInt(date_arr[0]);
	int month = ConvertInt(date_arr[1]);
	int day = ConvertInt(date_arr[2]);

	if (year < 2009) {
		this->_error_log = std::string("BitCoin is not created yet!");
		return -1;
	}
	if (month <= 0 || month > 12) {
		this->_error_log = "month should be between [1, 12]!";
		return -1;
	}
	if (month == 2) {
		if (day > 29) {
			this->_error_log = "February does not have more that a maximum of 29 days!";
			return -1;
		}
		if (!IsLeapYear(year)) {

			if (day > 28) {
				this->_error_log = date_arr[0] + " is a not a leap year, thus February can only have 28 days!";
				return -1;
			}
		}
	}
	if (day <= 0 || day > 31) {
		this->_error_log = "day should be between [1, 31]!";
		return -1;
	}
	
	return year * 10000 + month * 100 + day;
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

		if (line.empty() || date.empty()) {
			std::cout << "Error: No date or value is given" << std::endl;
			continue;
		}

		if (date == "date" && line == "value") {
			continue;
		}

		int key_date = IsDateCorrect(date);
		if (key_date == -1) {
			std::cout << "Error: '" << date << "' is incorrect because: '" << this->_error_log << "'" << std::endl;
			continue;
		}
		double value = ConvertDouble(line);
		if (value < 0 || value > 1000) {
			if (value < 0) {
				std::cout << "Error: ['"  <<  value <<"'] should be positive" << std::endl;
			} else {
				std::cout << "Error: ['" << value  <<"'] Too Big" << std::endl;
			}
			continue;
		}
		std::map<size_t, double>::iterator it = this->_exchange_db.upper_bound(key_date);
		if (it != _exchange_db.begin()) {
			--it;
			// std::cout << date << " => [" << it->first << "] " <<  value << " * " << it->second << " = " << value * it->second << std::endl;
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
		// std::cout << date << std::endl;
		_exchange_db[date] = exchange_rate;
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange() {
}


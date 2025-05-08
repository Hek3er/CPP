#include "PmergeMe.hpp"

PmergeMe::PmergeMe( char **av ) {
	this->_av = av;
}

PmergeMe::PmergeMe( PmergeMe& obj ) {

	*this = obj;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& obj) {
	if (this != &obj) {
		this->_av = obj._av;
		this->_vec = obj._vec;
	}
	return (*this);
}

std::string PmergeMe::CleanLine(std::string& line) const {
	std::string result;
	for (size_t i = 0; i < line.length(); i++) {
		if (!std::isspace(line[i])) {
			result += line[i];
		}
	}
	return result;
}

int PmergeMe::ConvertInt(const std::string& n) const {
	int res;
	std::stringstream out(n);
	out >> res;
	return res;
}

bool PmergeMe::IsCharacterCorrect( const std::string& n) const {
	for (size_t i = 0; i < n.length(); i++) {
		if (n[i] < '0' || n[i] > '9') {
			return false;
		}
	}
	return true;
}

void PmergeMe::SortDq( std::deque<int>& arr ) {
	if (arr.size() <= 1) {
		return ;
	}
	bool isOdd = false;
	int	 tail_element = 0;
	if (arr.size() % 2 != 0) {
		isOdd = true;
		tail_element = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;

	for (size_t i = 0; i < arr.size(); i+=2 ) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b) {
			pairs.push_back(std::make_pair(a,b));
		} else {
			pairs.push_back(std::make_pair(b, a));
		}
	}

	std::deque<int> main, pend;

	for (size_t i = 0; i < pairs.size(); i++) {
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	SortDq(main);

	std::deque<int> sorted = main;
	std::vector<int> seq = GetJacobSequence(pend.size());
	for (size_t i = 0; i < seq.size(); i++) {
		int idx = seq[i];
		std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), pend[idx]);
		sorted.insert(it, pend[idx]);
	}
	if (isOdd) {
		std::deque<int>::iterator it =std::lower_bound(sorted.begin(), sorted.end(), tail_element);
		sorted.insert(it, tail_element);
	}
	arr = sorted;
}

void PmergeMe::SortV( std::vector<int> & arr ) {

	if (arr.size() <= 1) {
		return ;
	}
	bool isOdd = false;
	int	 tail_element = 0;
	if (arr.size() % 2 != 0) {
		isOdd = true;
		tail_element = arr.back();
		arr.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < arr.size(); i+=2 ) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b) {
			pairs.push_back(std::make_pair(a,b));
		} else {
			pairs.push_back(std::make_pair(b, a));
		}
	}

	std::vector<int> main, pend;

	for (size_t i = 0; i < pairs.size(); i++) {
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	
	SortV(main);

	std::vector<int> sorted = main;
	std::vector<int> seq = GetJacobSequence(pend.size());
	for (size_t i = 0; i < seq.size(); i++) {
		int idx = seq[i];
		std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), pend[idx]);
		sorted.insert(it, pend[idx]);
	}
	if (isOdd) {
		std::vector<int>::iterator it =std::lower_bound(sorted.begin(), sorted.end(), tail_element);
		sorted.insert(it, tail_element);
	}
	arr = sorted;
}

std::vector<int> PmergeMe::GetJacobSequence( const size_t &size ) const {
	std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	for (size_t i = 2; i < size && jacob.back() < static_cast<int>(size); i++) {
		int val = (jacob[i - 1] + 2 * jacob[i - 2]);
		jacob.push_back(val);
	}

	std::vector<int> result;
	std::vector<bool> checks(size, false);

	int prev = 0;
	for (int i = jacob.size() - 1; i >= 0; i--) {
		if (jacob[i] >= (int)size) {
			jacob[i] = size - 1;
		}
		if (checks[jacob[i]] == false) { 
			result.push_back(jacob[i]);
			checks[jacob[i]] = true;
			
			for (int j = jacob[i] - 1; j > prev; j--) {
				if (checks[j] == false) {
					result.push_back(j);
					checks[j] = true;
					
				}
			}
			prev = jacob[i];
		}
	}
	if (checks[0] == false &&  size > 0) {
		result.push_back(0);
	}
	return result;
}

bool PmergeMe::StartBenchmark( void ) {
	if (gettimeofday(&_t1, 0) == -1) {
		std::cerr << "Error: could not get timeofday" << std::endl;
		return false;
	}
	return true;
}

bool PmergeMe::EndBenchmark( void ) {
	if (gettimeofday(&_t2, 0) == -1) {
		std::cerr << "Error: could not get timeofday" << std::endl;
		return false;
	}
	return true;
}

uint64_t PmergeMe::CalculateTime( void ) const {
	return (_t2.tv_sec - _t1.tv_sec) * 1000000 + (_t2.tv_usec - _t1.tv_usec);
}

void PmergeMe::Run( void ) {
	size_t pos = 0;

	for (size_t i = 1; _av[i] != NULL; i++) {
		std::string str(_av[i]);
		while ((pos = str.find(" ")) != std::string::npos) {
			std::string sub = str.substr(0, pos);
			sub = CleanLine(sub);
			if (!sub.empty()) {
				if (!IsCharacterCorrect(sub)) {
					std::cerr << "Error '" << sub << "'" << std::endl;
					return ;
				}
				this->_vec.push_back(ConvertInt(sub));
				this->_dq.push_back(ConvertInt(sub));
			}
			str.erase(0, pos + 1);
		}
		CleanLine(str);
		if (!IsCharacterCorrect(str)) {
			std::cerr << "Error '" << str << "'" << std::endl;
			return ;
		}
		if (!str.empty()) {
			this->_vec.push_back(ConvertInt(str));
			this->_dq.push_back(ConvertInt(str));
		}
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	if (!StartBenchmark()) return;

	SortV(_vec);

	if (!EndBenchmark()) return;

	uint64_t timeV = CalculateTime();

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	if (!StartBenchmark()) return;

	SortDq(_dq);

	if (!EndBenchmark()) return;

	uint64_t timeDq = CalculateTime();

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << _dq.size() << " elements with std::deque : " << timeDq << " us" <<std::endl;

}

PmergeMe::~PmergeMe() {
}


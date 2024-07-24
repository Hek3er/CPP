#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
	int				i;
	int 			n;
	int				flag;
	int 			oldest;
	int				index;
	std::string		s_index;
	Contact contacts[8];
	std::string	trim_str(std::string str);
public:
	PhoneBook();
	void Add(std::string f, std::string l, std::string nick, std::string d, std::string n);
	void ShowTable();
	void Search();
};
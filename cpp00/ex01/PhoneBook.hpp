#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
	int	i;
	int n;
	int	flag;
	Contact contacts[8];
public:
	PhoneBook() {
		i = 0;
		flag = 0;
		n = 0;
	}
	void Add(std::string f, std::string l, std::string nick, std::string d, int n) {
		if (i == 8) {
			flag = 1;
			i = 0;
		}
		contacts[i].FirstName = f;
		contacts[i].LastName = l;
		contacts[i].NickName = nick;
		contacts[i].PhoneNumber = n;
		contacts[i].DarkestSecret = d;
		i++;
	}
	void Show() {
		if (flag) {
			n = 8;
		} else {
			n = i;
		}
		for (int j = 0; j < n; j++) {
			std::cout << "First Name :" << contacts[j].FirstName<< std::endl;
			std::cout << "Last Name :" << contacts[j].LastName<< std::endl;
			std::cout << "NickName :" << contacts[j].NickName<< std::endl;
			std::cout << "DarkestSecret :" << contacts[j].DarkestSecret<< std::endl;
			std::cout << "PhoneNumber :" << contacts[j].PhoneNumber<< std::endl;
			std::cout << "----------------------------------" << std::endl;
		}
	}
};
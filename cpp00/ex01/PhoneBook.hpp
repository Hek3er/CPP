#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
	int			i;
	int 		n;
	int			flag;
	int 		oldest;
	int			index;
	Contact contacts[8];
	std::string	trim_str(std::string str) {
		if (str.length() > 10)
			str = str.substr(0, 9) + '.';
		return (str);
	}
public:
	PhoneBook() {
		i = 0;
		flag = 0;
		n = 0;
		oldest = 0;
	}

	void Add(std::string f, std::string l, std::string nick, std::string d, std::string n) {
		if (i == 8) {
			flag = 1;
			i = oldest;
			oldest++;
			if (oldest == 8)
				oldest = 0;
		}
		contacts[i].FirstName = f;
		contacts[i].LastName = l;
		contacts[i].NickName = nick;
		contacts[i].PhoneNumber = n;
		contacts[i].DarkestSecret = d;
		i++;
	}

	void ShowTable() {
		if (flag) {
			n = 8;
		} else {
			n = i;
		}
		std::string array[4] = {"Index", "First Name", "Last Name", "Nick Name"};
		for (int x = 0; x < 4; x++) {
			std::cout << "|" << "----------";
		}
		std::cout<<"|"<<std::endl<<"|";
		for (int x = 0; x < 4; x++) {
			std::cout << std::setw(10)<<array[x] << "|";
		}
		std::cout<<std::endl;
		for (int x = 0; x < 4; x++) {
			std::cout << "|" << "----------";
		}
		std::cout<<"|" <<std::endl;
		if (n == 0)
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int j = 0; j < n; j++) {
			std::cout << "|" << std::setw(10) <<j;
			std::cout << "|" << std::setw(10) << trim_str(contacts[j].FirstName);
			std::cout << "|" << std::setw(10) << trim_str(contacts[j].LastName);
			std::cout << "|" << std::setw(10) << trim_str(contacts[j].NickName) << "|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
	}

	void Search() {
		while (1) {
			std::cout << "Please Enter Index = ";
			std::cin >> index;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (index < 0 || index > 8 || index > n - 1) {
				std::cout << "Enter a valid index" << std::endl;
			}
			else
				break;
		}
		std::cout << std::endl << "		*** Contact " << index << " ***" << std::endl << std::endl; 
		std::cout << "First Name : " << contacts[index].FirstName << std::endl;
		std::cout << "Last Name : " << contacts[index].LastName << std::endl;
		std::cout << "NickName : " << contacts[index].NickName << std::endl;
		std::cout << "Darkest Secret : " << contacts[index].DarkestSecret << std::endl;
		std::cout << "Phone Number : " << contacts[index].PhoneNumber << std::endl << std::endl;
	}
};
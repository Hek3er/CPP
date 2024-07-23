#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

// define methods in PhoneBook class

std::string	PhoneBook::trim_str(std::string str) {
	if (str.length() > 10)
		str = str.substr(0, 9) + '.';
	return (str);
}

PhoneBook::PhoneBook() {
	i = 0;
	flag = 0;
	n = 0;
	oldest = 0;
}

void PhoneBook::Add(std::string f, std::string l, std::string nick, std::string d, std::string n) {
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

void PhoneBook::ShowTable() {
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

void PhoneBook::Search() {
	if (!n)
		return ;
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
	std::cout << std::endl << "		*** Contact [" << index << "]" << " ***" << std::endl << std::endl; 
	std::cout << "First Name : " << contacts[index].FirstName << std::endl;
	std::cout << "Last Name : " << contacts[index].LastName << std::endl;
	std::cout << "NickName : " << contacts[index].NickName << std::endl;
	std::cout << "Darkest Secret : " << contacts[index].DarkestSecret << std::endl;
	std::cout << "Phone Number : " << contacts[index].PhoneNumber << std::endl << std::endl;
}

void	GetInput(std::string& InputStr, std::string str)
{
	while (1) {
		std::cout << str;
		std::getline(std::cin, InputStr);
		if (InputStr[0])
			break;
	}
}

int main()
{
	std::string input;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkSecret;
	std::string	PhoneNumber;
	PhoneBook book;

	std::cout <<"		*** PHONE BOOK ***"<< std::endl<<std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
		{
			GetInput(FirstName, "First Name : ");
			GetInput(LastName, "Last Name : ");
			GetInput(NickName, "Nick Name : ");
			GetInput(DarkSecret, "Darkest Secret : ");
			GetInput(PhoneNumber, "Phone Number : ");
			std::cout << std::endl<<"		*** Contact Added ***"<< std::endl<< std::endl;
			book.Add(FirstName, LastName, NickName, DarkSecret, PhoneNumber);
		}
		if (!input.compare("SEARCH"))
		{
			book.ShowTable();
			book.Search();
		}
		if (!input.compare("EXIT")) {
			std::cout << std::endl << "		*** Good Bye ***" << std::endl;
			return (0);
		}
	}
	return (0);
}
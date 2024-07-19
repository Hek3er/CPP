#include <iostream>
#include "PhoneBook.hpp"

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

	std::cout << "		*** PHONE BOOK ***"<< std::endl<<std::endl;
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
#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;
	book.Add("Aymen", "Zainabi", "aym3n", "boo", 949493);
	book.Add("Amin", "boubrahim", "aminosar", "foo", 493);
	book.Add("abdou", "azlaf", "azz", "fodo", 212);
	// book.Add("qt", "rf", "azzd", "fodffo", 23412);
	// book.Add("Aymen", "Zainabi", "aym3n", "boo", 949493);
	// book.Add("Amin", "boubrahim", "aminosar", "foo", 493);
	// book.Add("abdou", "azlaf", "azz", "fodo", 212);
	// book.Add("qt", "rf", "azzd", "fodffo", 23412);
	// book.Add("ayoub", "mounaouir", "tikota", "pp", 3333);
	book.Show();
}
#include <cstddef>
#include <iostream>
#include <fstream>
#include <ostream>

int main(int ac, char **av)
{
	std::string str;
	size_t pos = 0;

	if (ac != 4) {
		std::cerr << "Please Provide a valid argument <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::fstream file(av[1]);

	if (!file) {
		std::cerr << "Unable To open file" << std::endl;
		return (1);
	}

	std::string rep = "while";

	while (!file.eof()) {
		std::getline(file, str);
		pos = str.find("while");
		if (pos != std::string::npos) {
			for (int i = 0; i < pos; i++) {
				std::cout << str[i] ;
			}
			std::cout <<"for"<< str.substr(pos + rep.length()) << std::endl;
			continue;
		}
		std::cout << str << std::endl;
	}

	// std::string str2 = "hell ye";

	// size_t pos = str2.find("world");
	// if (pos == std::string::npos) {
	// 	std::cout << "World doesnt exist" << std::endl;
	// 	return (1);
	// }

	// std::cout << "******" << str2.find("world") << std::endl;

	file.close();

}

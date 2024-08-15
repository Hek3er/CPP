#include <iostream>
#include <fstream>
#include <ostream>

int main(int ac, char **av)
{
	std::string str;
	std::string StringToReplace;
	std::string NewString;
	std::string FileName;
	std::string OutputFileName;
	size_t pos = 0;

	if (ac != 4) {
		std::cerr << "Please Provide a valid argument <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	StringToReplace = av[2];
	NewString = av[3];
	FileName = av[1];
	OutputFileName = FileName + ".replace";

	std::ifstream file(FileName);

	if (!file) {
		std::cerr << "Unable To open file" << std::endl;
		return (1);
	}

	// std::cout << "file.peek() = " << file.peek() << std::endl;
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << FileName <<  ": File is empty" << std::endl;
		return (1);
	}

	std::ofstream output(OutputFileName);

	while (!file.eof()) {
		std::getline(file, str);
			while (1) {
				pos = str.find(StringToReplace);
				if (pos != std::string::npos) {
					str.erase(pos, StringToReplace.length());
					str.insert(pos, NewString);
				}
				else {
					break;
				}
			}
		output << str << std::endl;
	}

	file.close();
	output.close();
}

#include <cstddef>
#include <iostream>
#include <fstream>
#include <ostream>

int main(int ac, char **av)
{
	std::string str;
	std::string StringToReplace;
	std::string StringToBeReplaced;
	std::string FileName;
	std::string OutputFileName;
	size_t pos = 0;

	if (ac != 4) {
		std::cerr << "Please Provide a valid argument <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	StringToReplace = av[2];
	StringToBeReplaced = av[3];
	FileName = av[1];
	OutputFileName = FileName + ".replace";

	std::ifstream file(FileName);
	std::ofstream output(OutputFileName);

	if (!file) {
		std::cerr << "Unable To open file" << std::endl;
		return (1);
	}

	while (!file.eof()) {
		std::getline(file, str);
			while (1) {
				pos = str.find(StringToReplace);
				if (pos != std::string::npos) {
					str.erase(pos, StringToReplace.length());
					str.insert(pos, StringToBeReplaced);
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

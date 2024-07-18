#include <iostream>

class Contact {
public:
	int			PhoneNumber;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkestSecret;
	Contact() {
		PhoneNumber = 0;
	}
};
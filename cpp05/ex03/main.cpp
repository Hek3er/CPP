#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	try
	{
		Intern someRandomIntern;
		AForm* rrf, *scf, *ppf;
		Bureaucrat b("aymen", 1);
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubery request", "Ayoub");
		ppf = someRandomIntern.makeForm("presedential pardon request", "Amine");

		b.signForm(*rrf);
		b.signForm(*scf);
		b.signForm(*ppf);
		b.executeForm(*rrf);
		b.executeForm(*scf);
		b.executeForm(*ppf);
	}
	catch(std::string &e) {
		std::cerr << e << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

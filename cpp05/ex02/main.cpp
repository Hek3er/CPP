#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try
	{
		ShrubberyCreationForm	shrub("home");
		RobotomyRequestForm		robot("home2");
		PresidentialPardonForm	president("home3");

		Bureaucrat				boss("boss", 1);
		Bureaucrat				noob("noob", 144);

		boss.executeForm(shrub);
		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(president);
		boss.executeForm(shrub);
		noob.executeForm(shrub);
		boss.executeForm(robot);
		noob.executeForm(robot);
		boss.executeForm(president);
		noob.executeForm(president);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	return (0);
}

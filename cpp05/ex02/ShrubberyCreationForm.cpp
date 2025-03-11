#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& obj ) : AForm(obj.getName(), 145, 137), _target(obj._target) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& obj) {
	if (this != &obj) {
		this->_target = obj._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned() || executor.getGrade() > this->getSignGrade() || executor.getGrade() > this->getSignExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::string 	file_name = this->_target + "_shrubbery";
	std::ofstream	output(file_name.c_str());
	if (output.is_open()) {
        output << "    *\n";
        output << "   ***\n";
        output << "  *****\n";
        output << " *******\n";
        output << "    |\n";
        output << "    |\n";
		std::cout << "\033[1;32mFile Created!\033[0m" << std::endl;
    } else {
		std::cerr << "\033[1;31mFailed to create a file\033[0m" << std::endl;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}


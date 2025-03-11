SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp   
CC = c++ 
NAME = main
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEADER =  Bureaucrat.hpp AForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp
OSRC = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OSRC)
	@echo "compiling.. "
	@$(CC) $(CFLAGS) $(OSRC) -o $(NAME) 

%.o : %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@echo "Removing Object files.."
	@rm -rf $(OSRC)

fclean: clean
	@echo "Removing Exec"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean

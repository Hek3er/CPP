SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
CC = c++
NAME = main
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEADER =  Animal.hpp Dog.hpp Cat.hpp  WrongAnimal.hpp WrongCat.hpp Brain.hpp
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
